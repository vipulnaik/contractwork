<?php
$mysqli = new mysqli("localhost", "username", "password", "database name");
$mysqli->set_charset("utf8");
$imagesPath = "(project folder)/access-portal/images/";
$generateGraphCmdBase = "python3 (project folder)/python/graph.py --label --top 30 ";
?>
