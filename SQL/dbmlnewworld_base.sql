DROP TABLE IF EXISTS LigneDeCommande, UnitMesLot, Distribution, LotProd, Commande, Produire, ListQuestUser, Variete, Utilisateur, Produit, Ouverture, Jour, Distributeur, Rayon, Role,  Employe, UniteMesure, Horaire, ListQuestChoix, QuestionChoix, ListeQuestion, Reponse, Parcelle, ModeProd;

/*CREATE TABLE `Distributeur`(`distribId` INTEGER,`distribLib` VARCHAR(25),`distribAdress` VARCHAR(25),`distribViille` VARCHAR(25),`distribCP` VARCHAR(5),`distribDescr` VARCHAR(200),primary key(`distribId`));

CREATE TABLE `ModeProd`(`numeroModeProd` INTEGER,`nomModeProd` VARCHAR(25),primary key(`numeroModeProd`));

CREATE TABLE `Parcelle`(`parcelleNum` INTEGER,`parcelleNom` VARCHAR(25),`parcelleAdress` VARCHAR(25),`parcelleLat` INTEGER,`parcelleLong` INTEGER,`parcelleModeProdId` INTEGER,`parcelleImg` VARCHAR(25),`numeroModeProd` INTEGER NOT NULL, foreign key (`numeroModeProd`) references ModeProd(`numeroModeProd`),primary key(`parcelleNum`));

CREATE TABLE `Reponse`(`reponseNum` INTEGER,`reponseLib` VARCHAR(25),primary key(`reponseNum`));

CREATE TABLE `ListeQuestion`(`listQuestNum` INTEGER,`listQuestLib` VARCHAR(25),primary key(`listQuestNum`));

CREATE TABLE `QuestionChoix`(`questchoixNum` INTEGER,`questchoixLib` VARCHAR(25),`reponseNum` INTEGER NOT NULL, foreign key (`reponseNum`) references Reponse(`reponseNum`),primary key(`questchoixNum`));

CREATE TABLE `ListQuestChoix`(`listQuestNum` INTEGER NOT NULL,`questchoixNum` INTEGER NOT NULL, foreign key (`listQuestNum`) references ListeQuestion(`listQuestNum`), foreign key (`questchoixNum`) references QuestionChoix(`questchoixNum`),primary key(`listQuestNum`,`questchoixNum`));

CREATE TABLE `UniteMesure`(`unitemesNum` INTEGER,`unetemesLib` VARCHAR(5),primary key(`unitemesNum`));

CREATE TABLE `Employe`(`employeNum` INTEGER,`employeNom` VARCHAR(25),`employePrenom` VARCHAR(25),`employePseudo` VARCHAR(25),`employeMdP` VARCHAR(25),primary key(`employeNum`));

CREATE TABLE `Role`(`roleId` INTEGER,`roleLib` VARCHAR(25),primary key(`roleId`));

CREATE TABLE `Rayon`(`rayonNum` INTEGER,`rayonLib` VARCHAR(25),`rayonImg` VARCHAR(25),primary key(`rayonNum`));

CREATE TABLE `Jour`(`jourId` INTEGER,`jourLibelle` VARCHAR(8),primary key(`jourId`));

CREATE TABLE `Ouverture`(`heureOuvertureMatin` TIME,`heureFermetureMatin` TIME,`heureOuvertureApresMidi` TIME,`heureFermetureApresMidi` TIME,`distribId` INTEGER NOT NULL,`jourId` INTEGER NOT NULL, foreign key (`distribId`) references Distributeur(`distribId`), foreign key (`jourId`) references Jour(`jourId`),primary key(`distribId`,`jourId`));

CREATE TABLE `Produit`(`produitNum` INTEGER,`produitNom` VARCHAR(25),`produitImg` VARCHAR(300),`produitValid` BOOL,`rayonNum` INTEGER NOT NULL, foreign key (`rayonNum`) references Rayon(`rayonNum`),primary key(`produitNum`));

CREATE TABLE `Utilisateur`(`userId` INTEGER,`userPseudo` VARCHAR(25),`userMdp` VARCHAR(25),`userMail` VARCHAR(25),`userImg` VARCHAR(25),`userDescr` VARCHAR(25),`userNom` VARCHAR(25),`userPrenom` VARCHAR(25),`userAdress` VARCHAR(50),`userVille` VARCHAR(25),`userCP` VARCHAR(5),`userTel` VARCHAR(10),`userValid` BOOL,`roleId` INTEGER NOT NULL, foreign key (`roleId`) references Role(`roleId`),primary key(`userId`));

CREATE TABLE `Variete`(`varieteNum` INTEGER,`varieteNom` VARCHAR(25),`varieteImg` VARCHAR(300),`varieteDescr` VARCHAR(200),`varieteValid` VARCHAR(200),`produitNum` INTEGER NOT NULL, foreign key (`produitNum`) references Produit(`produitNum`),primary key(`varieteNum`));

CREATE TABLE `ListQuestUser`(`listQuestNum` INTEGER NOT NULL,`userId` INTEGER NOT NULL, foreign key (`listQuestNum`) references ListeQuestion(`listQuestNum`), foreign key (`userId`) references Utilisateur(`userId`),primary key(`listQuestNum`,`userId`));

CREATE TABLE `Produire`(`rayonNum` INTEGER NOT NULL,`userId` INTEGER NOT NULL, foreign key (`rayonNum`) references Rayon(`rayonNum`), foreign key (`userId`) references Utilisateur(`userId`),primary key(`rayonNum`,`userId`));

CREATE TABLE `Commande`(`cmdNum` INTEGER,`cmdPrix` FLOAT,`cmdDate` DATE,`userId` INTEGER NOT NULL, foreign key (`userId`) references Utilisateur(`userId`),primary key(`cmdNum`));

CREATE TABLE `LotProd`(`lotprodNum` INTEGER,`lotprodPrixU` FLOAT,`lotprodQte` FLOAT,`lotprodUniteId` INTEGER,`lotprodDescr` VARCHAR(200),`lotprodDateRecolte` INTEGER,`lotprodDLC` INTEGER,`lotprodParcelleId` INTEGER,`parcelleNum` INTEGER NOT NULL,`varieteNum` INTEGER NOT NULL, foreign key (`parcelleNum`) references Parcelle(`parcelleNum`), foreign key (`varieteNum`) references Variete(`varieteNum`),primary key(`lotprodNum`));

CREATE TABLE `Distribution`(`distribId` INTEGER NOT NULL,`lotprodNum` INTEGER NOT NULL, foreign key (`distribId`) references Distributeur(`distribId`), foreign key (`lotprodNum`) references LotProd(`lotprodNum`),primary key(`distribId`,`lotprodNum`));

CREATE TABLE `UnitMesLot`(`unitemesNum` INTEGER NOT NULL,`lotprodNum` INTEGER NOT NULL, foreign key (`unitemesNum`) references UniteMesure(`unitemesNum`), foreign key (`lotprodNum`) references LotProd(`lotprodNum`),primary key(`unitemesNum`,`lotprodNum`));

CREATE TABLE `LigneDeCommande`(`LDCQte` FLOAT,`lotprodNum` INTEGER NOT NULL,`cmdNum` INTEGER NOT NULL,`distribId` INTEGER NOT NULL, foreign key (`lotprodNum`) references LotProd(`lotprodNum`), foreign key (`cmdNum`) references Commande(`cmdNum`), foreign key (`distribId`) references Distributeur(`distribId`),primary key(`lotprodNum`,`cmdNum`));


source dbmlnewworld_data.sql;*/