INSERT INTO Rayon VALUES
(0, "Légumes"),
(1, "Fruits"),
(2, "Viande");

INSERT INTO Question VALUES
(0, "Quel est le nom de votre animal de compagnie?"),
(1, "Quel est votre livre préfèré?"),
(2, "Qui est votre héro d'enfance");

INSERT INTO Label VALUES
(0, "Conventionnel", "conventionnel.png"),
(1, "Biologique", "biologique.png"),
(2, "Durable", "durable.png"),
(3, "Raisonnée", "raisonnee.png");

INSERT INTO Jour VALUES
(0, "Lundi"),
(1, "Mardi"),
(2, "Mercredi"),
(3, "Jeudi"),
(4, "Vendredi"),
(5, "Samedi"),
(6, "Dimanche");

INSERT INTO Ville VALUES
(0, "Gap", "0500"),
(1, "Moutiers", "73600"),
(2, "Embrun", "05200"),
(3, "Gréoux-les-bains", "04800");

INSERT INTO Unite VALUES
(0, "kg"),
(1, "piece"),
(2, "litre");

INSERT INTO Produit VALUES
(0, "Pomme", 1, 0, 1),
(1, "Poire", 1, 0, 1),
(2, "salade", 1, 1, 0),
(3, "tomate", 1, 0, 0);

INSERT INTO Variete VALUES
(0, "Granny smith", "Acidulé et verte", "granny_smith.png", 1, 0),
(1, "Golden", "Sucré et dorée", "golden.png", 1, 0),
(2, "Williams", "Charnue et délicate", "williams.png", 1, 1),
(3, "Batavia", "Sucré", "batavia.png", 1, 2),
(4, "Coeur de boeuf", "Volumineuse", "coeur_de_boeuf.png", 1, 3);

INSERT INTO Adresse VALUES
(0, "13 Rue Carnot", 0),
(1, "Place Verdun", 0),
(2, "106 Rue des tilleuls", 1),
(3, "zone d\'Entraigues", 2),
(4, "5 Rue Carnot", 0),
(5, "2 Rue des tilleuls", 2),
(6, "7 Rue Pasteur", 1),
(7, "3 Rue George Pompidou", 0),
(8, "Rue des oliviers", 3),
(9, "Gaston Boyer", 0);

INSERT INTO Utilisateur (userId, userNom, userPrenom, userMail, userEtat, userDateInscription, userTelephone, userMdp, userReponseSecurite, phraseId, adresseId) VALUES
(0, "Lebeau", "Mélanie", "melanie33130@live.fr", 0, "2017-10-02", "0492684532", "ab4f63f9ac65152575886860dde480a1", "black rock shooter", 2, 4),
(1, "Rostain", "Peterson", "petitourson05@hotmail.fr", 0, "2018-01-15", "0493648525", "ab4f63f9ac65152575886860dde480a1", "le petit ourson", 1, 7),
(2, "Vanlerberghe", "Michaël", "mvanlerberghe04@gmail.com", 0, "2017-12-23", "0493657836", "ab4f63f9ac65152575886860dde480a1", "Mononoke", 0, 8),
(3, "Iori", "Maxime", "computerdestroyeur05@gmail.com", 0, "2018-03-10", "0493783515", "ab4f63f9ac65152575886860dde480a1", "Le guide du hacking", 1, 9),
(4, "Jouffreau", "Théo", "theojouffreau@hotmail.com", 0, "2018-03-10", "0492345675", "ab4f63f9ac65152575886860dde480a1", "Tintin au tibet", 1, 9);

INSERT INTO Relai VALUES
(0, 1/*, "Lycée Dominique Villard"*/),
(1, 2/*, "Au panier vert"*/),
(2, 3/*, "La graine de lin"*/),
(3, 0/*, "Le panier carnot"*/);

INSERT INTO Distributeur VALUES
(0, 1),
(1, 2);

INSERT INTO Ouverture VALUES
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 0, 0),
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 0, 1),
("08:00:00", "12:00:00", "13:00:00", "15:00:00", 0, 2),
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 0, 3),
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 0, 4),
("09:00:00", "12:00:00", "14:00:00", "19:00:00", 1, 0),
("09:00:00", "12:00:00", "14:00:00", "19:00:00", 1, 1),
("09:00:00", "12:00:00", "14:00:00", "19:00:00", 1, 3),
("09:00:00", "12:00:00", "14:00:00", "19:00:00", 1, 4),
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 2, 0),
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 2, 1),
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 2, 4),
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 2, 5),
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 3, 0),
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 3, 1),
("08:00:00", "12:00:00", "14:00:00", "18:00:00", 3, 2);

INSERT INTO Producteur VALUES
(0, "Maxime Iori a une grande expérience dans la pomme", "maxime_iori.png", 1, 3),
(1, "Théo Jouffreau cultive de bonnes tomates", "theo_jouffreau", 1, 4);

INSERT INTO RelaisPossible VALUES
(0, 0),
(1, 0),
(2, 1),
(3, 1);

INSERT INTO Parcelle VALUES
(0, "39° 17′ N", "76° 36′ O", 0),
(1, "40° 17′ N", "76° 36′ O", 0),
(2, "39° 17′ N", "80° 36′ O", 1),
(3, "22° 17′ N", "76° 36′ O", 1);

INSERT INTO VerificationParcelle VALUES
("2016-05-17", 0, 0),
("2016-05-17", 1, 1),
("2017-03-12", 2, 2),
("2017-03-12", 3, 3);

INSERT INTO Lot VALUES
(0, 25, 1, 2.50, "2018-03-28", "2018-04-04", 0, 1),
(1, 50, 1, 1.30, "2018-03-27", "2018-04-03", 1, 0),
(2, 25, 1, 3.20, "2018-03-29", "2018-04-05", 2, 4),
(3, 70, 1, 2.50, "2018-03-30", "2018-04-06", 0, 1);

