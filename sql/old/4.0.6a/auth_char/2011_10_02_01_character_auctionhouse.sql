-- characters auctionhouse
DROP TABLE IF EXISTS `auctionhouse`;
CREATE TABLE IF NOT EXISTS `auctionhouse` (
  `id` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `auctioneerguid` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `itemguid` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `itemowner` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `buyoutprice` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `time` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `buyguid` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `lastbid` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `startbid` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `deposit` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `item_guid` (`itemguid`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;
