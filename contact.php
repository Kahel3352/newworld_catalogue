<html lang="en">
 <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <title>NewWorld</title>
    <!-- Font Awesome -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    <!-- Bootstrap core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <!-- Material Design Bootstrap -->
    <link href="css/mdb.min.css" rel="stylesheet">
    <!-- Your custom styles (optional) -->
    <link href="css/style.css" rel="stylesheet">
</head>

<body>           
<!-- Form contact -->
<form action="contact.php" method="post">

    <p class="h5 text-center mb-4">Nous contacter</p>

    <div class="md-form">
        <i class="fa fa-envelope prefix grey-text"></i>
        <input type="email" id="mail" class="form-control" name="mail">
        <label for="mail">Votre mail</label>
    </div>

    <div class="md-form">
        <i class="fa fa-tag prefix grey-text"></i>
        <input type="text" id="subject" class="form-control" name="subject">
        <label for="subject">Objet</label>
    </div>

    <div class="md-form">
        <i class="fa fa-pencil prefix grey-text"></i>
        <textarea type="text" id="message" class="md-textarea" style="height: 100px" name="message"></textarea>
        <label for="message">Votre message</label>
    </div>

    <div class="text-center">
        <button class="btn btn-unique color1" name="Send">Send <i class="fa fa-paper-plane-o ml-1"></i></button>
    </div>

</form>
<!-- Form contact -->

<!--PHP Form-->
<?php
include 'connect_base.php';

//s'il est passé par le formulaire
if (isset($_POST['mail'])&&isset($_POST['mail'])&& isset($_POST['mail']))
{
    $mail=$_POST['mail'];
    $subject=$_POST['subject'];
    $message=$_POST['message'];
    $datetime = date("Y-m-d H:i:s");
    $adresse_ip = $_SERVER['REMOTE_ADDR'];

    $request_ip="SELECT dateContact FROM Contact WHERE ipContact='".$adresse_ip."'";
    $search_ipdate=$cnx->query($request_ip);
    #$bool_ipdate=var_dump($search_ipdate->num_rows!=0);

    if ($search_ipdate->num_rows!=0) {
        $selectid="SELECT max(id) FROM Contact  WHERE ipContact='".$adresse_ip."'";
        $requestDateDiff="SELECT DATEDIFF('".$search_ipdate[$selectid]."','".$datetime."')";
        echo $requestDateDiff;
        }
    //si aucun n'est vide
    
    if(!empty($mail)&& !empty($subject) && !empty($message))
    {
        
        $request='INSERT INTO Contact (objetContact,mailContact,messageContact,dateContact,ipContact) VALUES ("'.$subject.'", "'.$mail.'", "'.$message.'", "'.$datetime.'","'.$adresse_ip.'")';

        $cnx->query($request);
    }
    else
        echo "Vous devez saisir tout les champs";
}
?>
<!--PHP Form-->
<script type="text/javascript" src="js/jquery-3.2.1.min.js"></script>
    <!-- Bootstrap tooltips -->
    <script type="text/javascript" src="js/popper.min.js"></script>
    <!-- Bootstrap core JavaScript -->
    <script type="text/javascript" src="js/bootstrap.min.js"></script>
    <!-- MDB core JavaScript -->
    <script type="text/javascript" src="js/mdb.min.js"></script>
</body>


</html>           