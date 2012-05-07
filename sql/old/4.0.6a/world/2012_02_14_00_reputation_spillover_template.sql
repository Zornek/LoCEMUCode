ALTER TABLE `reputation_spillover_template`    
ADD COLUMN `faction5` SMALLINT(6) UNSIGNED DEFAULT '0' NOT NULL AFTER `rank_4`,   
ADD COLUMN `rate_5` FLOAT DEFAULT '0' NOT NULL AFTER `faction5`,    
ADD COLUMN `rank_5` TINYINT(3) UNSIGNED DEFAULT '0' NOT NULL AFTER `rate_5`;
 
UPDATE `reputation_spillover_template` SET `faction5`=1134,`rate_5`=0.25,`rank_5`=7 WHERE `faction` IN (72,47,54,930,69);
UPDATE `reputation_spillover_template` SET `faction5`=1133,`rate_5`=0.25,`rank_5`=7 WHERE `faction` IN (76,530,911,81,68);

REPLACE INTO `reputation_spillover_template`VALUES
(1134,72,0.25,7,47,0.27,7,54,0.25,7,930,0.25,7,69,0.25,7),
(1133,76,0.25,7,530,0.27,7,911,0.25,7,81,0.25,7,68,0.25,7);