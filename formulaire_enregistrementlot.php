<?php
	include('connect_base.php');
?>
<html>
<head>
	<meta charset="utf-8">
	<title>Enregister un lot</title>
	<!-- Font Awesome -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    <!--Mon CSS -->
	<link rel="stylesheet" type="text/css" href="style.css">
	<!-- Bootstrap core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <!-- Material Design Bootstrap -->
    <link href="css/mdb.min.css" rel="stylesheet">
    <!-- Your custom styles (optional) -->
    <link href="css/style.css" rel="stylesheet">
</head>
<body>
	<div id="formEnregistrementLot" class="card mx-xl-5">
		<!-- Card body -->
    	<div class="card-body">
    		<!-- Default form subscription -->
        	<form>
            	<p class="h4 text-center py-4">Subscribe</p>

            	<!-- Default input name -->
            	<label for="defaultFormCardNameEx" class="grey-text font-weight-light">Your name</label>
            	<input type="text" id="defaultFormCardNameEx" class="form-control">
            
            	<br>

            	<!-- Default input email -->
            	<label for="defaultFormCardEmailEx" class="grey-text font-weight-light">Your email</label>
	            <input type="email" id="defaultFormCardEmailEx" class="form-control">

    	        <div class="text-center py-4 mt-3">
        	        <button class="btn btn-outline-purple" type="submit">Send<i class="fa fa-paper-plane-o ml-2"></i></button>
            	</div>
        	</form>
        	<!-- Default form subscription -->

    	</div>
    	<!-- Card body -->

	</div>
<!-- Card -->

<!--Script -->
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