<div class="modal-content">
            <form id="register" class="ajax-auth" inscriptionNW method="post">
                <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                    <span aria-hidden="true">&times;</span>
                </button>

                <div class="text-center">
                    <h3 class="h3-responsive"><i class="fa fa-user"></i> s'authentifier avec:</h3>       
                    <!--
                    	wsl_render_auth_widget
                    	WordPress Social Login 2.3.0.
                    	http://wordpress.org/plugins/wordpress-social-login/
                    -->
                    <style type="text/css">
                    .wp-social-login-connect-with{}.wp-social-login-provider-list{}.wp-social-login-provider-list a{}.wp-social-login-provider-list img{}.wsl_connect_with_provider{}
                    </style>
                    <div class="wp-social-login-widget">

                    	<div class="wp-social-login-connect-with">Se connecter avec:</div>

                    	<div class="wp-social-login-provider-list">

                    		<a rel="nofollow" href="http://gthom.btsinfogap.org/newWorld/wp-login.php?action=wordpress_social_authenticate&#038;mode=login&#038;provider=Facebook&#038;redirect_to=http%3A%2F%2Fgthom.btsinfogap.org%2FnewWorld%2F" title="Connecter avec Facebook" class="wp-social-login-provider wp-social-login-provider-facebook" data-provider="Facebook">
                    			<img alt="Facebook" title="Connect with Facebook" src="images/facebook.png" />
                    		</a>

                    		<a rel="nofollow" href="http://gthom.btsinfogap.org/newWorld/wp-login.php?action=wordpress_social_authenticate&#038;mode=login&#038;provider=Google&#038;redirect_to=http%3A%2F%2Fgthom.btsinfogap.org%2FnewWorld%2F" title="Connect with Google" class="wp-social-login-provider wp-social-login-provider-google" data-provider="Google">
                    			<img alt="Google" title="Connect with Google" src="images/google.png" />
                    		</a>

                    		<a rel="nofollow" href="http://gthom.btsinfogap.org/newWorld/wp-login.php?action=wordpress_social_authenticate&#038;mode=login&#038;provider=Twitter&#038;redirect_to=http%3A%2F%2Fgthom.btsinfogap.org%2FnewWorld%2F" title="Connect with Twitter" class="wp-social-login-provider wp-social-login-provider-twitter" data-provider="Twitter">
                    			<img alt="Twitter" title="Connect with Twitter" src="images/twitter.png" />
                    		</a>
                    	</div>
                    	<div class="wp-social-login-widget-clearing"></div>
                    </div>
                    <!-- wsl_render_auth_widget -->
                    <hr>
                    <h3 class="h3-responsive"> Or:</h3>
                </div>
                <!-- fin du textcenter-->
                <p class="status"></p>
                <input type="hidden" id="signonsecurity" name="signonsecurity" value="256874042c" /><input type="hidden" name="_wp_http_referer" value="/" />
                <div class="md-form">
                    <i class="fa fa-user prefix"></i>
                    <input type="text" id="signonname" class="form-control" name="nom">
                    <label for="signonname">Votre nom</label>
                </div>
                <div class="md-form">
                    <i class="fa fa-user prefix"></i>
                    <input type="text" id="signonpname" class="form-control" name="prenom">
                    <label for="signonpname">Votre prénom</label>
                </div>
                <div class="md-form">
                    <i class="fa fa-envelope prefix"></i>
                    <input type="text" id="email" class="form-control" name="email">
                    <label for="email">Votre email</label>
                </div>

                <div class="md-form">
                    <i class="fa fa-lock prefix"></i>
                    <input type="password" id="signonpassword" class="form-control" name="passwd1">
                    <label for="signonpassword">Votre mot de passe</label>
                </div>

                <div class="md-form">
                    <i class="fa fa-lock prefix"></i>
                    <input type="password" id="password2" class="form-control" name="passwd2">
                    <label for="password2">Repetez le mot de passe</label>
                </div>

                <div class="text-center">
                    <button class="submit_button btn btn-primary" type="submit" value="SIGNUP">S'inscrire</button>

                    <hr>

                    <p>Vous avez déjà un compte? <a href="#" id="pop_login">Se connecter</a></p>
                </div>
                    <!--
                            <div class="g-recaptcha" data-sitekey="6LflIQ4TAAAAAEx83MeF_efgHI7acclgM_UYe1Ov"></div>
                    -->
            </form>
        </div><!--.modal-content-->