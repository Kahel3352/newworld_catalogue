 <?php
        include('connect_base.php');
?>
<html>
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
    <?php
    if (isset($_POST['name'], $_POST['surname'], $_POST['pseudo'], $_POST['street'], $_POST['cdepst'], $_POST['city'], $_POST['mail'], $_POST['tel'], $_POST['pass'], $_POST['passverif']) and $_POST['name']!='' and $_POST['surname']!='' and $_POST['pseudo']!='' and $_POST['mail']!='') {

         if($_POST['pass']==$_POST['passverif']) {
      // vérification de la longueur du mot de passe
      if(strlen($_POST['pass'])>=6) {
          // echappement des variables pour pouvoir les mettre dans une requette SQL
          $name = $cnx->escape_string($_POST['name']);
          $surname = $cnx->escape_string($_POST['surname']);
          $pseudo = $cnx->escape_string($_POST['pseudo']);
          $street = $cnx->escape_string($_POST['street']);
          $cdepst = $cnx->escape_string($_POST['cdepst']);
          $city = $cnx->escape_string($_POST['city']);
          $mail = $cnx->escape_string($_POST['mail']);
          $tel = $cnx->escape_string($_POST['tel']);
          $pass = $cnx->escape_string($_POST['pass']);
          
          // vérification de l'absence d'utilisateur inscrit sous ce pseudo
          $result = $cnx->query('SELECT numeroUser from Utilisateur where pseudoUser="'.$pseudo.'"');
          if ($result === false OR $result->num_rows < 1) {
             echo 'INSERT INTO Utilisateur(pseudoUser, mdpUser,mailUser, nomUser, prenomUser, cdePostalUser, villeUser, adressUser, telUser) values ( "'.$pseudo.'","'.$pass.'","'.$mail.'","'.$name.'","'.$surname.'","'.$cdepst.'","'.$city.'","'.$street.'","'.$tel.'")';

              // enregistrement des informations
              if($cnx->query('INSERT INTO Utilisateur(pseudoUser, mdpUser,mailUser, nomUser, prenomUser, cdePostalUser, villeUser, adressUser, telUser) values ( "'.$pseudo.'","'.$pass.'","'.$mail.'","'.$name.'","'.$surname.'","'.$cdepst.'","'.$city.'","'.$street.'","'.$tel.'")'))
              {

                $form = false;
                echo '<div>Vous avez été inscrit. Vous pouvez vous connecter.<br></div>';
              }
              else {
                $form = true;
                $message = "Une erreur est survenue lors de l'inscription.";
              }
          }
          else {
            $form = true;
            $message = 'Identifiant déjà assigné.';
          }
      }
      else {
        $form = true;
        $message = 'Le mot de passe que vous avez entré contient moins de 6 caractères.';
      }
    }
    else {
      $form = true;
      $message = 'Les mots de passe que vous avez entré ne sont pas identiques.';
    }
  }
  else {
    $form = true;
  }
  if($form) {
    //On affiche un message sil y a lieu
    if(isset($message))
    {
        echo '<div>'.$message.'</div>';
    }
        
    }
?>

<!-- Form register -->
<form action="inscription.php" method="post">
    <p class="h5 text-center mb-4">Sign up</p>

    <div class="md-form">
        <i class="fa fa-user prefix grey-text"></i>
        <input type="text" id="Form-name" name="name" class="form-control">
        <label for="Form-name">Nom</label>
    </div>
    <div class="md-form">
        <i class="fa fa-user prefix grey-text"></i>
        <input type="text" id="Form-surname" name="surname" class="form-control">
        <label for="Form-surname">Prénom</label>
    </div>

    <div class="md-form">
        <i class="fa fa-user prefix grey-text"></i>
        <input type="text" id="Form-pseudo" name="pseudo" class="form-control">
        <label for="Form-pseudo">Pseudo</label>
    </div>

    <?php
      include 'genereAdresse.php';
    ?>
    <div class="md-form">
        <i class="fa fa-envelope prefix grey-text"></i>
        <input type="email" id="Form-mail" name="mail" class="form-control">
        <label for="Form-mail">Email</label>
    </div>

    <div class="md-form">
        <i class="fa fa-pencil prefix grey-text"></i>
        <input type="text" id="Form-tel" name="tel" class="form-control">
        <label for="Form-tel">Numéro de téléphone</label>
    </div>
    

    <div class="md-form">
        <i class="fa fa-lock prefix grey-text"></i>
        <input type="password" id="Form-pass" name="pass" class="form-control">
        <label for="Form-pass">Mot de passe</label>
    </div>


    <div class="md-form">
        <i class="fa fa-lock prefix grey-text"></i>
        <input type="password" id="Form-passverif" name="passverif" class="form-control">
        <label for="Form-passverif">Vérification du mot de passe</label>
    </div>

    <div class="text-center">
        <button class="btn btn-teal" type="submit">S'inscrire</button>
    </div>

</form>

<!-- Form register -->

   <script type="text/javascript" src="js/jquery-3.2.1.min.js"></script>
  <script src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>

    <!-- Bootstrap tooltips -->
    <script type="text/javascript" src="js/popper.min.js"></script>
    <!-- Bootstrap core JavaScript -->
    <script type="text/javascript" src="js/bootstrap.min.js"></script>
    <!-- MDB core JavaScript -->
    <script type="text/javascript" src="js/mdb.min.js"></script>
</body>
</html>