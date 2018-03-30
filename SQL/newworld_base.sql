DROP TABLE IF EXISTS Avis, Consommateur, Commande, Lot, VerificationParcelle, Parcelle, RelaiPossible, Producteur, Ouverture, Distributeur, Relai, Utilisateur, Adresse, Variete, Produit, Unite, Ville, Jour, Question, Label, Rayon;

CREATE TABLE `Rayon`(`rayonId` INTEGER,`rayonLibelle` VARCHAR(25),primary key(`rayonId`));

CREATE TABLE `Question`(`phraseId` INTEGER,`phraseIntitule` VARCHAR(100),primary key(`phraseId`));

CREATE TABLE `Label`(`labelId` INTEGER,`labelNom` VARCHAR(25),`labelLogo` VARCHAR(25),primary key(`labelId`));

CREATE TABLE `Jour`(`jourId` INTEGER,`jourNom` VARCHAR(8),primary key(`jourId`));

CREATE TABLE `Ville`(`villeId` INTEGER,`villeNom` VARCHAR(25),`villeCP` VARCHAR(5),primary key(`villeId`));

CREATE TABLE `Unite`(`uniteId` INTEGER,`uniteLibelle` VARCHAR(25),primary key(`uniteId`));

CREATE TABLE `Produit`(`produitId` INTEGER,`produitLibelle` VARCHAR(25),`produitValid` BOOL,`uniteId` INTEGER NOT NULL,`rayonId` INTEGER NOT NULL, foreign key (`uniteId`) references Unite(`uniteId`), foreign key (`rayonId`) references Rayon(`rayonId`),primary key(`produitId`));

CREATE TABLE `Variete`(`varieteId` INTEGER,`varieteNom` VARCHAR(25),`varieteDescr` VARCHAR(25),`varieteImg` VARCHAR(25),`varieteValid` BOOL,`produitId` INTEGER NOT NULL, foreign key (`produitId`) references Produit(`produitId`),primary key(`varieteId`));

CREATE TABLE `Adresse`(`adresseId` INTEGER,`adresseRue` VARCHAR(25),`villeId` INTEGER NOT NULL, foreign key (`villeId`) references Ville(`villeId`),primary key(`adresseId`));

CREATE TABLE `Utilisateur`(`userId` INTEGER,`userNom` VARCHAR(25),`userPrenom` VARCHAR(25),`userMail` VARCHAR(25),`userEtat` ENUM('valide', 'en cours'),`userDateInscription` DATETIME,`userFacebook` VARCHAR(25),`userGoogle` VARCHAR(25),`userTelephone` VARCHAR(25),`userMdp` VARCHAR(32),`userReponseSecurite` VARCHAR(150),`userNbEchecConnexion` INTEGER,`adresseId` INTEGER NOT NULL,`phraseId` INTEGER NOT NULL, foreign key (`adresseId`) references Adresse(`adresseId`), foreign key (`phraseId`) references Question(`phraseId`),primary key(`userId`));

CREATE TABLE `Relai`(`relaiId` INTEGER,`adresseId` INTEGER NOT NULL, foreign key (`adresseId`) references Adresse(`adresseId`),primary key(`relaiId`));

CREATE TABLE `Distributeur`(`relaiId` INTEGER NOT NULL,`userId` INTEGER NOT NULL, foreign key (`relaiId`) references Relai(`relaiId`), foreign key (`userId`) references Utilisateur(`userId`),primary key(`relaiId`,`userId`));

CREATE TABLE `Ouverture`(`heureOuvertureMatin` TIME,`heureFermetureMatin` TIME,`heureOuvertureApresMidi` TIME,`heureFermetureApresMidi` TIME,`relaiId` INTEGER NOT NULL,`jourId` INTEGER NOT NULL, foreign key (`relaiId`) references Relai(`relaiId`), foreign key (`jourId`) references Jour(`jourId`),primary key(`relaiId`,`jourId`));

CREATE TABLE `Producteur`(`producteurId` INTEGER,`producteurDescr` VARCHAR(250),`producteurImg` VARCHAR(25),`producteurValid` BOOL,`userId` INTEGER NOT NULL, foreign key (`userId`) references Utilisateur(`userId`),primary key(`producteurId`));

CREATE TABLE `RelaisPossible`(`relaiId` INTEGER NOT NULL,`producteurId` INTEGER NOT NULL, foreign key (`relaiId`) references Relai(`relaiId`), foreign key (`producteurId`) references Producteur(`producteurId`),primary key(`relaiId`,`producteurId`));

CREATE TABLE `Parcelle`(`parcelleId` INTEGER,`parcelleLongitude` VARCHAR(24),`parcelleLatitude` VARCHAR(24),`producteurId` INTEGER NOT NULL, foreign key (`producteurId`) references Producteur(`producteurId`),primary key(`parcelleId`));

CREATE TABLE `VerificationParcelle`(`verifDate` INTEGER,`labelId` INTEGER NOT NULL,`parcelleId` INTEGER NOT NULL, foreign key (`labelId`) references Label(`labelId`), foreign key (`parcelleId`) references Parcelle(`parcelleId`),primary key(`labelId`,`parcelleId`));

CREATE TABLE `Lot`(`lotId` INTEGER,`lotQte` FLOAT,`lotQteMin` FLOAT,`lotPrix` FLOAT,`lotDLC` DATE,`lotDateProduction` DATE,`parcelleId` INTEGER NOT NULL,`varieteId` INTEGER NOT NULL, foreign key (`parcelleId`) references Parcelle(`parcelleId`), foreign key (`varieteId`) references Variete(`varieteId`),primary key(`lotId`));

CREATE TABLE `Commande`(`cmdId` INTEGER,`cmdDate` DATETIME,`cmdQte` FLOAT,`cmdEtat` ENUM('en cours', 'valide'),`relaiId` INTEGER NOT NULL,`lotId` INTEGER NOT NULL, foreign key (`relaiId`) references Relai(`relaiId`), foreign key (`lotId`) references Lot(`lotId`),primary key(`cmdId`));

CREATE TABLE `Consommateur`(`cmdId` INTEGER NOT NULL,`userId` INTEGER NOT NULL, foreign key (`cmdId`) references Commande(`cmdId`), foreign key (`userId`) references Utilisateur(`userId`),primary key(`cmdId`,`userId`));

CREATE TABLE `Avis`(`avisId` INTEGER,`avisCommentaire` VARCHAR(250),`avisNote` INTEGER,`producteurId` INTEGER NOT NULL,`cmdId` INTEGER NOT NULL,`userId` INTEGER NOT NULL, foreign key (`producteurId`) references Producteur(`producteurId`), foreign key (`cmdId`,`userId`) references Consommateur(`cmdId`,`userId`),primary key(`avisId`));

source newworld_data.sql