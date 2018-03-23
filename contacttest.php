<!DOCTYPE html>
<html>
<head>
    <title></title>
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
<div class="modal-dialog" role="document">
        <div class="modal-content">
            <form id="login" class="ajax-auth" action="" method="post">

                <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                    <span aria-hidden="true">&times;</span>
                </button>

                <div class="text-center">
                    <h3 class="h3-responsive"><i class="fa fa-user"></i> Nous contacter </h3>
                   
                    <!--
                        wsl_render_auth_widget
                        WordPress Social Login 2.3.0.
                        http://wordpress.org/plugins/wordpress-social-login/
                    -->

                    <style type="text/css">
                    .wp-social-login-connect-with{}.wp-social-login-provider-list{}.wp-social-login-provider-list a{}.wp-social-login-provider-list img{}.wsl_connect_with_provider{}</style>

                    <div class="wp-social-login-widget">

                        <div class="wp-social-login-connect-with">Se connecter avec:</div>

                        <div class="wp-social-login-provider-list">
                <!--
                <div class="fb-login-button" data-max-rows="1" data-size="medium" data-show-faces="true" data-auto-logout-link="false"></div>
                -->
                            <fb:login-button scope="public_profile,email" onlogin="checkLoginState();">
                        </fb:login-button>
                            <a rel="nofollow" href="http://gthom.btsinfogap.org/newWorld//wp-login.php?action=wordpress_social_authenticate&#038;mode=login&#038;provider=Google&#038;redirect_to=http%3A%2F%2Fgthom.btsinfogap.org%2FnewWorld%2F" title="Connect with Google" class="wp-social-login-provider wp-social-login-provider-google" data-provider="Google">
                                <img alt="Google" title="Connect with Google" src="https://mdbootstrap.com/wp-content/plugins/wordpress-social-login/assets/img/32x32/wpzoom/google.png" />
                            </a>

                            <a rel="nofollow" href="http://gthom.btsinfogap.org/newWorld/wp-login.php?action=wordpress_social_authenticate&#038;mode=login&#038;provider=Twitter&#038;redirect_to=http%3A%2F%2Fgthom.btsinfogap.org%2FnewWorld%2F" title="Connect with Twitter" class="wp-social-login-provider wp-social-login-provider-twitter" data-provider="Twitter">
                                <img alt="Twitter" title="Connect with Twitter" src="https://mdbootstrap.com/wp-content/plugins/wordpress-social-login/assets/img/32x32/wpzoom/twitter.png" />
                            </a>

                        </div>

                        <div class="wp-social-login-widget-clearing"></div>

                    </div>
                    <!-- wsl_render_auth_widget -->
                    <hr>
                    <h3 class="h3-responsive"> Or:</h3>
                    <p class="status"></p>
                    <input type="hidden" id="security" name="security" value="aaeeddaed125" /><input type="hidden" name="_wp_http_referer" value="/" />
                    <div class="md-form">
                        <!--<label for="username">Votre identifiant</label>-->
                        <i class="fa fa-user prefix"></i>
                        <input type="text" id="username" class="form-control" name="username" placeholder="Identifiant">                
                    </div>

                    <div class="md-form">
                        <i class="fa fa-lock prefix"></i>
                        <input type="password" id="password" class="form-control" name="password" placeholder="Mot de passe">
                        <!--<label for="password">Votre mot de passe</label>-->
                    </div>

                    <div class="text-center">
                        <button class="submit_button btn btn-primary" type="submit" value="LOGIN">Se Connecter</button>
                    </div>

                    <hr>
                    <div class="text-center">
                        <p>Pas encore inscrit? <a href="#modal_register" id="pop_signup" data-toggle="modal" data-target="#modal_register">S'inscrire</a></p>
                        <p> Mot de passe <a href="passwordPerduNW.php">oublié?</a></p>
                    </div>
                </div>
                <!-- fin de la div textcenter -->
            </form>
            <!-- fin de la première fenêtre-->
        </div>
    </div>

<script type="text/javascript" src="js/jquery-3.2.1.min.js"></script>
    <!-- Bootstrap tooltips -->
    <script type="text/javascript" src="js/popper.min.js"></script>
    <!-- Bootstrap core JavaScript -->
    <script type="text/javascript" src="js/bootstrap.min.js"></script>
    <!-- MDB core JavaScript -->
    <script type="text/javascript" src="js/mdb.min.js"></script>
</body>
</html>