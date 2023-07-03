#!/usr/bin/env python3
#
# SPDX-License-Identifier: Apache-2.0
# Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

"""This script will use the ocpp201 JSON configuration file passed as the script argument to 
    set VariableAttributes inside the tables that have been created in the database.

    This script requires an SQLite database that has been initialized using the 
    init_device_model_db.py script located in this folder.
    """


from pathlib import Path
import sqlite3
import json
import argparse


def insert_variable_attribute_value(component_name: str, variable_name: str, value: str, cur: sqlite3.Cursor):
    """Inserts a variable attribute value into the VARIABLE_ATTRIBUTE table

    Args:
        component_name (str): name of the component
        variable_name (str): name of the variable
        value (str): value that should be set
        cur (sqlite3.Cursor): sqlite3 cursor
    """
    statement = ("UPDATE VARIABLE_ATTRIBUTE "
                 f"SET 'VALUE' = '{str(value).lower() if type(value) is bool else value}' "
                 "WHERE VARIABLE_ID = ("
                 "SELECT VARIABLE.ID "
                 "FROM VARIABLE "
                 "JOIN COMPONENT ON COMPONENT.ID = VARIABLE.COMPONENT_ID "
                 f"WHERE COMPONENT.NAME = '{component_name}' "
                 f"AND VARIABLE.NAME = '{variable_name}') "
                 "AND TYPE_ID = 0; ")
    cur.execute(statement)


def insert_config(config_file: Path, cur: sqlite3.Cursor):
    """Inserts the values given in config file into the VARIABLE_ATTRIBUTE table 

    Args:
        config_file (Path): Path to the config file
        cur (sqlite3.Cursor): sqlite3 cursor
    """
    with open(config_file, 'r') as f:
        config: dict = json.loads(f.read())
        for component in config:
            for variable in config[component]:
                value = config[component][variable]
                insert_variable_attribute_value(
                    component, variable, value, cur)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        formatter_class=argparse.RawTextHelpFormatter, description="OCPP2.0.1 Database Confing Loading")
    parser.add_argument("--config", metavar="CONFIG",
                        help="Path to config file to write AttributeVariable values into the database", required=True)
    parser.add_argument("--db", metavar="CONFIG",
                        help="Path to the database", required=True)

    args = parser.parse_args()
    config = Path(args.config)
    db_path = Path(args.db)
    con = sqlite3.connect(db_path)
    insert_config(config, con.cursor())
    con.commit()
    con.close()

################################# TODO #################################
# add support for attribute values (other than actual and for monitors #
# Add proper json schema for the conifg                                #
########################################################################
