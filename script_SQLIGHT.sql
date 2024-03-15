PRAGMA foreign_keys = 0;
CREATE TABLE IF NOT EXISTS sqlitestudio_temp_table0(
    name       TEXT    NOT NULL,
    start_time INTEGER,
    end_time   INTEGER,
    name_m     TEXT    NOT NULL
);
INSERT INTO sqlitestudio_temp_table0 (name,
	start_time,
	end_time,
	name_m)
SELECT DISTINCT name,
	start_time,
	end_time,
	name_m
FROM time;
DROP TABLE IF EXISTS time;
CREATE TABLE IF NOT EXISTS time 
AS SELECT DISTINCT * FROM sqlitestudio_temp_table0;
DROP  TABLE IF EXISTS sqlitestudio_temp_table0;
PRAGMA foreign_keys = 1