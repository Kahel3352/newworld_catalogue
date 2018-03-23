<?php 

/*
 * 		activation de la variable $_SESSION
 */
session_start();

/* 
 * 		connection à la base utilisateurs
 */
if (!($cnx = mysqli_connect("localhost", "mlebeau", "passf203", "dbmlnewworld"))) {
	echo ("connection impossible ".$cnx->connect_error);
	return false;
	echo __FILE__,":",__LINE__,": Connecté";
}
	
$cnx->query("SET NAMES utf8");

/*  
 * 	variables de configuration
 */
 
 $url_home = "index.php";

?>
