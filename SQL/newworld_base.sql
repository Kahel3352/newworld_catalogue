DROP TABLE IF EXISTS Lot, Article, Parcelle, Label, Avis, Consommateur, RelaiPossible, Commande, Producteur, Ouverture, Distributeur, Relai, Utilisateur, Adresse, Securite, Variete, Produit, Unite, Ville, Jour, Question, Rayon;

CREATE TABLE `Rayon`(`idRayon` INTEGER,`libelle` VARCHAR(25),primary key(`idRayon`));

CREATE TABLE `Question`(`idPhrase` INTEGER,`phrase` VARCHAR(100),primary key(`idPhrase`));

CREATE TABLE `Jour`(`idJour` INTEGER,`nom` VARCHAR(8),primary key(`idJour`));

CREATE TABLE `Ville`(`idVille` INTEGER,`nom` VARCHAR(25),`codePostal` VARCHAR(5),primary key(`idVille`));

CREATE TABLE `Unite`(`idUnite` INTEGER,`libelle` VARCHAR(25),primary key(`idUnite`));

CREATE TABLE `Produit`(`idProduit` INTEGER,`libelle` VARCHAR(25),`idUnite` INTEGER NOT NULL,`idRayon` INTEGER NOT NULL, foreign key (`idUnite`) references Unite(`idUnite`), foreign key (`idRayon`) references Rayon(`idRayon`),primary key(`idProduit`));

CREATE TABLE `Variete`(`idVariete` INTEGER,`nom` VARCHAR(25),`description` VARCHAR(25),`image` VARCHAR(25),`idProduit` INTEGER NOT NULL, foreign key (`idProduit`) references Produit(`idProduit`),primary key(`idVariete`));

CREATE TABLE `Adresse`(`idAdresse` INTEGER,`rue` VARCHAR(25),`idVille` INTEGER NOT NULL, foreign key (`idVille`) references Ville(`idVille`),primary key(`idAdresse`));

CREATE TABLE `Utilisateur`(`idUtilisateur` INTEGER,`nom` VARCHAR(25),`prenom` VARCHAR(25),`mail` VARCHAR(25),`etat` ENUM('valide', 'en cours'),`dteInscription` DATETIME,`facebook` VARCHAR(25),`google` VARCHAR(25),`telephone` VARCHAR(25),`mdp` VARCHAR(32),`reponseSecurite` VARCHAR(150),`nbEchecConnexion` INTEGER,`idAdresse` INTEGER NOT NULL,`idPhrase` INTEGER NOT NULL, foreign key (`idAdresse`) references Adresse(`idAdresse`), foreign key (`idPhrase`) references Question(`idPhrase`),primary key(`idUtilisateur`));

CREATE TABLE `Relai`(`idRelai` INTEGER,`idAdresse` INTEGER NOT NULL, foreign key (`idAdresse`) references Adresse(`idAdresse`),primary key(`idRelai`));

CREATE TABLE `Distributeur`(`idRelai` INTEGER NOT NULL,`idUtilisateur` INTEGER NOT NULL, foreign key (`idRelai`) references Relai(`idRelai`), foreign key (`idUtilisateur`) references Utilisateur(`idUtilisateur`),primary key(`idRelai`,`idUtilisateur`));

CREATE TABLE `Ouverture`(`heureOuvertureMatin` TIME,`heureFermetureMatin` TIME,`heureOuvertureApresMidi` TIME,`heureFermetureApresMidi` TIME,`idRelai` INTEGER NOT NULL,`idJour` INTEGER NOT NULL, foreign key (`idRelai`) references Relai(`idRelai`), foreign key (`idJour`) references Jour(`idJour`),primary key(`idRelai`,`idJour`));

CREATE TABLE `Producteur`(`idProducteur` INTEGER,`description` VARCHAR(250),`image` VARCHAR(25),`idUtilisateur` INTEGER NOT NULL, foreign key (`idUtilisateur`) references Utilisateur(`idUtilisateur`),primary key(`idProducteur`));

CREATE TABLE `Commande`(`idCommande` INTEGER,`date` DATETIME,`qte` FLOAT,`etat` ENUM('en cours', 'valide'),`idRelai` INTEGER NOT NULL, foreign key (`idRelai`) references Relai(`idRelai`),primary key(`idCommande`));

CREATE TABLE `RelaiPossible`(`idRelai` INTEGER NOT NULL,`idProducteur` INTEGER NOT NULL, foreign key (`idRelai`) references Relai(`idRelai`), foreign key (`idProducteur`) references Producteur(`idProducteur`),primary key(`idRelai`,`idProducteur`));

CREATE TABLE `Consommateur`(`idCommande` INTEGER NOT NULL,`idUtilisateur` INTEGER NOT NULL, foreign key (`idCommande`) references Commande(`idCommande`), foreign key (`idUtilisateur`) references Utilisateur(`idUtilisateur`),primary key(`idCommande`,`idUtilisateur`));

CREATE TABLE `Avis`(`idAvis` INTEGER,`commentaire` VARCHAR(250),`note` INTEGER,`idProducteur` INTEGER NOT NULL,`idCommande` INTEGER NOT NULL,`idUtilisateur` INTEGER NOT NULL, foreign key (`idProducteur`) references Producteur(`idProducteur`), foreign key (`idCommande`,`idUtilisateur`) references Consommateur(`idCommande`,`idUtilisateur`),primary key(`idAvis`));

CREATE TABLE `Label`(`idLabel` INTEGER,`nom` VARCHAR(25),`logo` VARCHAR(25),`derniereVerif` DATE,`idProducteur` INTEGER NOT NULL, foreign key (`idProducteur`) references Producteur(`idProducteur`),primary key(`idLabel`));

CREATE TABLE `Parcelle`(`idParcelle` INTEGER,`idProducteur` INTEGER NOT NULL, foreign key (`idProducteur`) references Producteur(`idProducteur`),primary key(`idParcelle`));

CREATE TABLE `Article`(`idParcelle` INTEGER NOT NULL,`idVariete` INTEGER NOT NULL, foreign key (`idParcelle`) references Parcelle(`idParcelle`), foreign key (`idVariete`) references Variete(`idVariete`),primary key(`idParcelle`,`idVariete`));

CREATE TABLE `Lot`(`idLot` INTEGER,`qte` FLOAT,`qteMin` FLOAT,`prix` FLOAT,`dteLimite` DATE,`dteProduction` DATE,`idCommande` INTEGER NOT NULL,`idParcelle` INTEGER NOT NULL,`idVariete` INTEGER NOT NULL, foreign key (`idCommande`) references Commande(`idCommande`), foreign key (`idParcelle`,`idVariete`) references Article(`idParcelle`,`idVariete`),primary key(`idLot`));

source newworld_data.sql