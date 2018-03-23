-- phpMyAdmin SQL Dump
-- version 4.2.12deb2+deb8u2
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Ven 23 Février 2018 à 09:53
-- Version du serveur :  5.5.40-0+wheezy1
-- Version de PHP :  5.6.30-0+deb8u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `dbmlnewworld`
--

-- Contenu de la table `Employe`
--

INSERT INTO `Employe` (`employeNum`, `employeNom`, `employePrenom`, `employePseudo`, `employeMdP`) VALUES
(0, 'admin', 'admin', 'admin', 'admin'),
(1, 'Lebeau', 'Mélanie', 'Nanie', 'melanie33');

--
-- Contenu de la table `Rayon`
--

INSERT INTO `Rayon` (`rayonNum`, `rayonLib`, `rayonImg`) VALUES
(0, 'Fruit et Légumes', '/ImgRessources/rayonFL.jpg');
--
-- Contenu de la table `Produit`
--

INSERT INTO `Produit` (`produitNum`, `produitNom`, `produitImg`, `produitValid`, `rayonNum`) VALUES
(0, 'Tomate', 'tomate.png', 0, 0),
(1, 'Poire', 'poire.png', 0, 0),
(2, 'Carotte', 'carotte.png', 1, 0),
(3, 'Theo','theo.png', 0, 0);

--
-- Contenu de la table `Utilisateur`
--

INSERT INTO `Role` (`roleId`, `roleLib`) VALUES
(0, 'Consommateur'),
(1, 'Producteur'),
(2, 'Distributeur');

--
-- Contenu de la table `Utilisateur`
--

INSERT INTO `Utilisateur` (`userId`, `userPseudo`, `userMdp`, `userMail`, `userImg`, `userDescr`, `userNom`, `userPrenom`, `userAdress`, `userVille`, `userCP`, `userTel`, `userValid`, `roleId`) VALUES
(0, 'Nanie', 'melanie33', 'melanie33130@live.fr', '0', 'Je suis Nanie', 'Lebeau', 'Mélanie', '109 Boulevard Georges Pompidou', 'Gap', '05000', '0650993930',1,1),
(1, 'Wanheda', 'skaikruWanheda', 'wanheda@live.fr', '0', 'Je viens de la série the ', 'Griffin', 'Clarke', '48 Rue des Hedas', 'Polis', '48100', '0626483698',1,1),
(2, 'Heda', 'heda', 'heda@live.fr', '0', 'Je viens de la série the ', 'Woods', 'Lexa', '48 Rue des Hedas', 'Polis', '48100', '0626469630',0,1),
(3, 'SpaceWalker', 'spacewalker', 'spacewalker@live.fr', '0', 'Je viens de la série the ', 'Collins', 'Finn', '22 Boulevard de la Folie de TonDc', 'Ark', '10048', '0626464564',0,1),
(4, 'Reaper', 'reaper', 'faucheurreaper@live.fr', '0', 'Je viens de la série the ', 'Reaper', 'Faucheur', '2 Impasse du Cannibalisme', 'Mount Weather', '02100', '0626464455',0,1);



--
-- Contenu de la table `Variete`
--

INSERT INTO `Variete` (`varieteNum`, `varieteNom`, `varieteImg`, `varieteDescr`, `varieteValid`, `produitNum`) VALUES
(0, 'Coeur de Boeuf', 'Variété fragile de tomate, elle est réputée pour son goût, sa chair abondante et la rareté de ses pépins', 'tomate_coeurdeboeuf.png', 0, 0),
(1, 'Bleue Osu', 'Variété rare de tomate bleue, au gout fade qui necessite un bon assaisonnement', 'tomate_bleueosu.png', 0, 0),
(2, 'Yellow Stuffer', 'Variété de tomate jaune qui ressemble fortement à un poivron, idéale à farcir', 'tomate_yellowstuffer.png', 0, 0),
(3, 'Comice', 'Variété fragile de poire, à la chaire blanche, juteuse et fondante, extrêmement parfumée et sucrée.', 'poire_comice.png', 0, 1),
(4, 'Blanche des Vosges', 'Variété ancienne de carotte, elle est gouteuse si elle est récoltée jeune, utilisé  en fourragère pour des récoltes de racines plus âgées.', 'carotte_blanchedesvosges.png', 0, 2);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
