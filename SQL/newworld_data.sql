INSERT INTO Rayon VALUES
(0, "Légumes"),
(1, "Fruits"),
(2, "Viande");

INSERT INTO Question VALUES
(0, "Quel est le nom de votre animal de compagnie?"),
(1, "Quel est votre livre préfèré?"),
(2, "Qui est votre héro d'enfance");

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
(0, "Pomme", 0, 1),
(1, "Poire", 0, 1),
(2, "salade", 1, 0),
(3, "tomate", 0, 0);

INSERT INTO Variete VALUES
(0, "Granny smith", "Acidulé et verte", "granny_smith.png", 0),
(1, "Golden", "Sucré et dorée", "golden.png", 0),
(2, "Williams", "Charnue et délicate", "williams.png", 1),
(3, "Batavia", "Sucré", "batavia.png", 2),
(4, "Coeur de boeuf", "Volumineuse", "coeur_de_boeuf.png", 3);

INSERT INTO Adresse VALUES
(0, "13 Rue Carnot", 0),
(1, "Place Verdun", 0),
(2, "106 Rue des tilleuls", 1),
(3, "zone d\'Entraigues", 2),
(4, "5 Rue Carnot", 0),
(5, "2 Rue des tilleuls", 2),
(6, "7 Rue Pasteur", 1),
(7, "3 Rue George Pompidou", 0),
(8, "Rue des oliviers", 3);

INSERT INTO Utilisateur (idUtilisateur, nom, prenom, mail, etat, dteInscription, telephone, mdp, reponseSecurite, idPhrase, idAdresse) VALUES
(0, "Lebeau", "Mélanie", "melanie33130@live.fr", 0, "2017-10-02", "0492684532", "ab4f63f9ac65152575886860dde480a1", "black rock shooter", 2, 4),
(1, "Rostain", "Peterson", "petitourson05@hotmail.fr", 0, "2018-01-15", "0493648525", "ab4f63f9ac65152575886860dde480a1", "le petit ourson", 1, 7),
(2, "Vanlerberghe", "Michaël", "mvanlerberghe04@gmail.com", 0, "2017-12-23", "0493657836", "ab4f63f9ac65152575886860dde480a1", "Mononoke", 0, 8);

INSERT INTO Relai
(0, 1/*, "Lycée Dominique Villard"*/),
(1, 2/*, "Au panier vert"*/);