/*
 Navicat Premium Data Transfer

 Source Server         : MySqlStuManger
 Source Server Type    : MySQL
 Source Server Version : 80035
 Source Host           : localhost:3306
 Source Schema         : stumanagedb

 Target Server Type    : MySQL
 Target Server Version : 80035
 File Encoding         : 65001

 Date: 10/12/2023 15:48:02
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student`  (
  `studentid` int NOT NULL AUTO_INCREMENT,
  `sname` text CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `age` int NULL DEFAULT NULL,
  `grade` int NULL DEFAULT NULL,
  `sclass` int NULL DEFAULT NULL,
  `phonenumber` text CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL,
  PRIMARY KEY (`studentid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 371 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES (1, '毛南蓉', 18, 2, 3, '17755908510');
INSERT INTO `student` VALUES (2, '开痴灵', 19, 3, 1, '17755908510');
INSERT INTO `student` VALUES (3, '东郭言文', 20, 3, 2, '17755908510');
INSERT INTO `student` VALUES (4, '晁听枫', 20, 4, 6, '17755908510');
INSERT INTO `student` VALUES (5, '祈茂才', 19, 2, 5, '17755908510');
INSERT INTO `student` VALUES (6, '绍愉', 20, 3, 8, '17755908510');
INSERT INTO `student` VALUES (7, '金洋洋', 20, 2, 6, '17755908510');
INSERT INTO `student` VALUES (8, '井秀媚', 21, 2, 6, '17755908510');
INSERT INTO `student` VALUES (9, '莘英慧', 22, 2, 5, '17755908510');
INSERT INTO `student` VALUES (10, '历从灵', 21, 3, 8, '17755908510');
INSERT INTO `student` VALUES (11, '完颜晨璐', 19, 1, 1, '17755908510');
INSERT INTO `student` VALUES (12, '郭千易', 22, 1, 5, '17755908510');
INSERT INTO `student` VALUES (13, '尤俊杰', 18, 2, 2, '17755908510');
INSERT INTO `student` VALUES (14, '季恨荷', 21, 2, 3, '17755908510');
INSERT INTO `student` VALUES (15, '礼含娇', 22, 2, 3, '17755908510');
INSERT INTO `student` VALUES (16, '环雨伯', 18, 1, 7, '17755908510');
INSERT INTO `student` VALUES (17, '吴鹏飞', 21, 4, 5, '17755908510');
INSERT INTO `student` VALUES (18, '党三姗', 18, 1, 7, '17755908510');
INSERT INTO `student` VALUES (19, '禹倚', 19, 4, 1, '17755908510');
INSERT INTO `student` VALUES (20, '东方水蓉', 20, 1, 9, '17755908510');
INSERT INTO `student` VALUES (21, '辟向南', 22, 1, 9, '17755908510');
INSERT INTO `student` VALUES (22, '闭弘阔', 19, 2, 3, '17755908510');
INSERT INTO `student` VALUES (23, '皮元槐', 19, 2, 7, '17755908510');
INSERT INTO `student` VALUES (24, '御元', 18, 2, 6, '17755908510');
INSERT INTO `student` VALUES (25, '孙芳洁', 18, 1, 1, '17755908510');
INSERT INTO `student` VALUES (26, '衅英光', 20, 1, 4, '17755908510');
INSERT INTO `student` VALUES (27, '衡碧菡', 21, 2, 6, '17755908510');
INSERT INTO `student` VALUES (28, '钭语彤', 21, 4, 5, '17755908510');
INSERT INTO `student` VALUES (29, '缑思敏', 18, 3, 6, '17755908510');
INSERT INTO `student` VALUES (30, '怀冉冉', 20, 1, 4, '17755908510');
INSERT INTO `student` VALUES (31, '钱昆纶', 19, 2, 5, '17755908510');
INSERT INTO `student` VALUES (32, '勇乐珍', 19, 4, 6, '17755908510');
INSERT INTO `student` VALUES (33, '永乐容', 22, 4, 5, '17755908510');
INSERT INTO `student` VALUES (34, '朴尹', 18, 4, 2, '17755908510');
INSERT INTO `student` VALUES (35, '唐燕楠', 18, 1, 8, '17755908510');
INSERT INTO `student` VALUES (36, '青高原', 19, 3, 1, '17755908510');
INSERT INTO `student` VALUES (37, '邴勃', 18, 1, 3, '17755908510');
INSERT INTO `student` VALUES (38, '空醉波', 19, 2, 9, '17755908510');
INSERT INTO `student` VALUES (39, '迮令美', 20, 2, 9, '17755908510');
INSERT INTO `student` VALUES (40, '运温纶', 20, 3, 1, '17755908510');
INSERT INTO `student` VALUES (41, '竭晨', 20, 4, 4, '17755908510');
INSERT INTO `student` VALUES (42, '溥晓兰', 20, 2, 5, '17755908510');
INSERT INTO `student` VALUES (43, '羿丹彤', 20, 4, 1, '17755908510');
INSERT INTO `student` VALUES (44, '充荡', 18, 2, 7, '17755908510');
INSERT INTO `student` VALUES (45, '骑香梅', 22, 3, 6, '17755908510');
INSERT INTO `student` VALUES (46, '姒寅', 19, 4, 9, '17755908510');
INSERT INTO `student` VALUES (47, '咸岳', 22, 3, 7, '17755908510');
INSERT INTO `student` VALUES (48, '邝淳静', 20, 1, 5, '17755908510');
INSERT INTO `student` VALUES (49, '树蔓菁', 22, 1, 4, '17755908510');
INSERT INTO `student` VALUES (50, '悉寄真', 18, 4, 3, '17755908510');
INSERT INTO `student` VALUES (51, '夏侯俊驰', 20, 3, 9, '17755908510');
INSERT INTO `student` VALUES (52, '欧阳宸', 22, 2, 2, '17755908510');
INSERT INTO `student` VALUES (53, '揭茵', 18, 3, 7, '17755908510');
INSERT INTO `student` VALUES (54, '析阳伯', 18, 1, 1, '17755908510');
INSERT INTO `student` VALUES (55, '蒿凝丝', 22, 4, 4, '17755908510');
INSERT INTO `student` VALUES (56, '融平卉', 18, 2, 4, '17755908510');
INSERT INTO `student` VALUES (57, '回凝竹', 22, 1, 5, '17755908510');
INSERT INTO `student` VALUES (58, '赖寄波', 19, 4, 5, '17755908510');
INSERT INTO `student` VALUES (59, '勾觅晴', 21, 2, 8, '17755908510');
INSERT INTO `student` VALUES (60, '鱼运良', 21, 2, 3, '17755908510');
INSERT INTO `student` VALUES (61, '宗思云', 20, 4, 6, '17755908510');
INSERT INTO `student` VALUES (62, '农悦欣', 18, 3, 3, '17755908510');
INSERT INTO `student` VALUES (63, '褚芷琪', 18, 1, 9, '17755908510');
INSERT INTO `student` VALUES (64, '伟子辰', 21, 4, 4, '17755908510');
INSERT INTO `student` VALUES (65, '纪默', 20, 1, 5, '17755908510');
INSERT INTO `student` VALUES (66, '源魄', 22, 3, 4, '17755908510');
INSERT INTO `student` VALUES (67, '隗宁', 18, 3, 4, '17755908510');
INSERT INTO `student` VALUES (68, '陶蕴秀', 18, 1, 5, '17755908510');
INSERT INTO `student` VALUES (69, '杨听然', 19, 1, 7, '17755908510');
INSERT INTO `student` VALUES (70, '乾欣可', 22, 4, 6, '17755908510');
INSERT INTO `student` VALUES (71, '府香春', 19, 3, 8, '17755908510');
INSERT INTO `student` VALUES (72, '谭怀蕾', 19, 4, 5, '17755908510');
INSERT INTO `student` VALUES (73, '典瑞绣', 20, 4, 5, '17755908510');
INSERT INTO `student` VALUES (74, '宛凌晴', 19, 1, 5, '17755908510');
INSERT INTO `student` VALUES (75, '熊优乐', 22, 3, 8, '17755908510');
INSERT INTO `student` VALUES (76, '库南莲', 22, 2, 6, '17755908510');
INSERT INTO `student` VALUES (77, '折语海', 19, 2, 1, '17755908510');
INSERT INTO `student` VALUES (78, '守优瑗', 19, 3, 3, '17755908510');
INSERT INTO `student` VALUES (79, '法如仪', 19, 1, 7, '17755908510');
INSERT INTO `student` VALUES (80, '刑梦竹', 20, 1, 4, '17755908510');
INSERT INTO `student` VALUES (81, '星嘉泽', 18, 4, 7, '17755908510');
INSERT INTO `student` VALUES (82, '姜瑞芝', 19, 1, 9, '17755908510');
INSERT INTO `student` VALUES (83, '欧沛文', 20, 4, 7, '17755908510');
INSERT INTO `student` VALUES (84, '茹水蕊', 18, 1, 6, '17755908510');
INSERT INTO `student` VALUES (85, '奕璞', 18, 1, 8, '17755908510');
INSERT INTO `student` VALUES (86, '太史德馨', 20, 4, 4, '17755908510');
INSERT INTO `student` VALUES (87, '项芷烟', 20, 4, 1, '17755908510');
INSERT INTO `student` VALUES (88, '严嘉禧', 21, 4, 9, '17755908510');
INSERT INTO `student` VALUES (89, '高如之', 20, 3, 5, '17755908510');
INSERT INTO `student` VALUES (90, '暨蝶梦', 22, 1, 3, '17755908510');
INSERT INTO `student` VALUES (91, '麴英彦', 19, 3, 7, '17755908510');
INSERT INTO `student` VALUES (92, '仇馨荣', 18, 4, 9, '17755908510');
INSERT INTO `student` VALUES (93, '春洛灵', 20, 1, 9, '17755908510');
INSERT INTO `student` VALUES (94, '郏香露', 20, 2, 1, '17755908510');
INSERT INTO `student` VALUES (95, '潮密思', 18, 1, 4, '17755908510');
INSERT INTO `student` VALUES (96, '乐夜梅', 18, 4, 2, '17755908510');
INSERT INTO `student` VALUES (97, '字尔晴雪凝', 22, 4, 2, '17755908510');
INSERT INTO `student` VALUES (98, '冒怡宁', 18, 1, 6, '17755908510');
INSERT INTO `student` VALUES (99, '钟傲霜', 22, 1, 9, '17755908510');
INSERT INTO `student` VALUES (100, '宓淳雅', 22, 2, 2, '17755908510');
INSERT INTO `student` VALUES (101, '学豆', 19, 2, 4, '17755908510');
INSERT INTO `student` VALUES (102, '白鹏翼', 18, 2, 9, '17755908510');
INSERT INTO `student` VALUES (103, '商林楠', 22, 1, 3, '17755908510');
INSERT INTO `student` VALUES (104, '籍波', 19, 3, 7, '17755908510');
INSERT INTO `student` VALUES (105, '国芸馨', 20, 4, 2, '17755908510');
INSERT INTO `student` VALUES (106, '敬熙怡', 19, 3, 5, '17755908510');
INSERT INTO `student` VALUES (107, '林欣愉', 20, 2, 6, '17755908510');
INSERT INTO `student` VALUES (108, '乙水瑶', 18, 3, 9, '17755908510');
INSERT INTO `student` VALUES (109, '申华芝', 18, 3, 9, '17755908510');
INSERT INTO `student` VALUES (110, '钮志行', 18, 4, 8, '17755908510');
INSERT INTO `student` VALUES (111, '歧欣美', 21, 3, 2, '17755908510');
INSERT INTO `student` VALUES (112, '隽鸿才', 20, 2, 3, '17755908510');
INSERT INTO `student` VALUES (113, '保代双', 21, 2, 5, '17755908510');
INSERT INTO `student` VALUES (114, '尚佑', 20, 4, 5, '17755908510');
INSERT INTO `student` VALUES (115, '管白容', 20, 3, 1, '17755908510');
INSERT INTO `student` VALUES (116, '笃依秋', 20, 2, 1, '17755908510');
INSERT INTO `student` VALUES (117, '虢北', 19, 2, 5, '17755908510');
INSERT INTO `student` VALUES (118, '萨理全', 21, 4, 4, '17755908510');
INSERT INTO `student` VALUES (119, '元兰若', 21, 1, 6, '17755908510');
INSERT INTO `student` VALUES (120, '闳觅露', 20, 1, 2, '17755908510');
INSERT INTO `student` VALUES (121, '但奇', 21, 4, 6, '17755908510');
INSERT INTO `student` VALUES (122, '戎栋', 22, 4, 7, '17755908510');
INSERT INTO `student` VALUES (123, '仪浩大', 20, 1, 2, '17755908510');
INSERT INTO `student` VALUES (124, '咎理群', 21, 1, 4, '17755908510');
INSERT INTO `student` VALUES (125, '粟凝海', 22, 1, 5, '17755908510');
INSERT INTO `student` VALUES (126, '丘真', 21, 4, 7, '17755908510');
INSERT INTO `student` VALUES (127, '矫飞双', 20, 1, 8, '17755908510');
INSERT INTO `student` VALUES (128, '次沛雯', 22, 2, 4, '17755908510');
INSERT INTO `student` VALUES (129, '宾谧', 22, 4, 7, '17755908510');
INSERT INTO `student` VALUES (130, '郦碧蓉', 21, 2, 6, '17755908510');
INSERT INTO `student` VALUES (131, '亢新柔', 21, 3, 6, '17755908510');
INSERT INTO `student` VALUES (132, '泉含云', 20, 1, 1, '17755908510');
INSERT INTO `student` VALUES (133, '称胤骞', 19, 2, 9, '17755908510');
INSERT INTO `student` VALUES (134, '母沈然', 22, 2, 5, '17755908510');
INSERT INTO `student` VALUES (135, '凌世英', 22, 3, 5, '17755908510');
INSERT INTO `student` VALUES (136, '樊秋英', 20, 4, 3, '17755908510');
INSERT INTO `student` VALUES (137, '龙安露', 18, 2, 4, '17755908510');
INSERT INTO `student` VALUES (138, '贺沈', 18, 1, 5, '17755908510');
INSERT INTO `student` VALUES (139, '望静秀', 22, 1, 5, '17755908510');
INSERT INTO `student` VALUES (140, '百海颖', 19, 4, 5, '17755908510');
INSERT INTO `student` VALUES (141, '委雅美', 22, 1, 9, '17755908510');
INSERT INTO `student` VALUES (142, '郎真茹', 22, 2, 2, '17755908510');
INSERT INTO `student` VALUES (143, '祁迪', 22, 3, 6, '17755908510');
INSERT INTO `student` VALUES (144, '西门梓涵', 22, 3, 1, '17755908510');
INSERT INTO `student` VALUES (145, '昔甫', 20, 1, 3, '17755908510');
INSERT INTO `student` VALUES (146, '卑浩思', 20, 2, 4, '17755908510');
INSERT INTO `student` VALUES (147, '似曼雁', 21, 4, 3, '17755908510');
INSERT INTO `student` VALUES (148, '种飞兰', 21, 4, 4, '17755908510');
INSERT INTO `student` VALUES (149, '胥祺瑞', 18, 2, 7, '17755908510');
INSERT INTO `student` VALUES (150, '宏傲南', 18, 2, 9, '17755908510');
INSERT INTO `student` VALUES (151, '买问风', 21, 3, 2, '17755908510');
INSERT INTO `student` VALUES (152, '勤晓慧', 21, 3, 9, '17755908510');
INSERT INTO `student` VALUES (153, '畅伟', 21, 1, 4, '17755908510');
INSERT INTO `student` VALUES (154, '枝昆琦', 21, 2, 5, '17755908510');
INSERT INTO `student` VALUES (155, '留海凡', 19, 4, 9, '17755908510');
INSERT INTO `student` VALUES (156, '荆静美', 21, 2, 8, '17755908510');
INSERT INTO `student` VALUES (157, '弥泰宁', 20, 3, 7, '17755908510');
INSERT INTO `student` VALUES (158, '蒉曼吟', 18, 2, 5, '17755908510');
INSERT INTO `student` VALUES (159, '鄂笑萍', 21, 1, 5, '17755908510');
INSERT INTO `student` VALUES (160, '菅同化', 18, 3, 7, '17755908510');
INSERT INTO `student` VALUES (161, '普乐逸', 22, 2, 8, '17755908510');
INSERT INTO `student` VALUES (162, '初洋然', 18, 1, 5, '17755908510');
INSERT INTO `student` VALUES (163, '员成济', 19, 2, 9, '17755908510');
INSERT INTO `student` VALUES (164, '郁清涵', 22, 1, 3, '17755908510');
INSERT INTO `student` VALUES (165, '接莹洁', 19, 3, 7, '17755908510');
INSERT INTO `student` VALUES (166, '吾娟巧', 20, 1, 7, '17755908510');
INSERT INTO `student` VALUES (167, '花贝莉', 18, 1, 8, '17755908510');
INSERT INTO `student` VALUES (168, '靖泰然', 20, 4, 1, '17755908510');
INSERT INTO `student` VALUES (169, '贾紫雪', 21, 4, 5, '17755908510');
INSERT INTO `student` VALUES (170, '易菁英', 22, 2, 3, '17755908510');
INSERT INTO `student` VALUES (171, '剑韶华', 20, 3, 5, '17755908510');
INSERT INTO `student` VALUES (172, '关嘉年', 22, 2, 4, '17755908510');
INSERT INTO `student` VALUES (173, '麦清雅', 20, 1, 7, '17755908510');
INSERT INTO `student` VALUES (174, '招凯安', 19, 3, 4, '17755908510');
INSERT INTO `student` VALUES (175, '於方', 22, 2, 4, '17755908510');
INSERT INTO `student` VALUES (176, '旁觅山', 22, 4, 9, '17755908510');
INSERT INTO `student` VALUES (177, '拱晴照', 22, 2, 1, '17755908510');
INSERT INTO `student` VALUES (178, '晋修文', 21, 1, 3, '17755908510');
INSERT INTO `student` VALUES (179, '杭咸', 20, 1, 1, '17755908510');
INSERT INTO `student` VALUES (180, '穰蒙', 19, 1, 3, '17755908510');
INSERT INTO `student` VALUES (181, '子车松', 19, 3, 3, '17755908510');
INSERT INTO `student` VALUES (182, '宰灿', 20, 1, 1, '17755908510');
INSERT INTO `student` VALUES (183, '汤清怡', 19, 1, 4, '17755908510');
INSERT INTO `student` VALUES (184, '王沛珊', 19, 2, 3, '17755908510');
INSERT INTO `student` VALUES (185, '驹嘉平', 18, 2, 4, '17755908510');
INSERT INTO `student` VALUES (186, '硕迎荷', 20, 2, 5, '17755908510');
INSERT INTO `student` VALUES (187, '牢群', 19, 4, 2, '17755908510');
INSERT INTO `student` VALUES (188, '希骞泽', 21, 2, 9, '17755908510');
INSERT INTO `student` VALUES (189, '睢飞珍', 19, 3, 1, '17755908510');
INSERT INTO `student` VALUES (190, '奇戈', 21, 4, 9, '17755908510');
INSERT INTO `student` VALUES (191, '潜阳霁', 19, 2, 4, '17755908510');
INSERT INTO `student` VALUES (192, '都琛', 19, 4, 2, '17755908510');
INSERT INTO `student` VALUES (193, '漫春华', 21, 4, 9, '17755908510');
INSERT INTO `student` VALUES (194, '叔琛瑞', 19, 2, 2, '17755908510');
INSERT INTO `student` VALUES (195, '奈和韵', 22, 2, 3, '17755908510');
INSERT INTO `student` VALUES (196, '资阑', 19, 3, 6, '17755908510');
INSERT INTO `student` VALUES (197, '葛涵韵', 20, 4, 7, '17755908510');
INSERT INTO `student` VALUES (198, '仲孙欣彤', 22, 4, 2, '17755908510');
INSERT INTO `student` VALUES (199, '薄小雯', 22, 2, 8, '17755908510');
INSERT INTO `student` VALUES (200, '捷冠玉', 18, 3, 4, '17755908510');
INSERT INTO `student` VALUES (201, '赤新雅', 20, 3, 1, '17755908510');
INSERT INTO `student` VALUES (202, '嵇芮安', 21, 2, 7, '17755908510');
INSERT INTO `student` VALUES (203, '郝怀芹', 20, 2, 9, '17755908510');
INSERT INTO `student` VALUES (204, '崔梦玉', 19, 1, 3, '17755908510');
INSERT INTO `student` VALUES (205, '山拔', 19, 1, 8, '17755908510');
INSERT INTO `student` VALUES (206, '占映', 18, 2, 9, '17755908510');
INSERT INTO `student` VALUES (207, '羊烨煜', 19, 1, 4, '17755908510');
INSERT INTO `student` VALUES (208, '邰孤阳', 20, 3, 5, '17755908510');
INSERT INTO `student` VALUES (209, '校芳苓', 18, 3, 5, '17755908510');
INSERT INTO `student` VALUES (210, '浦迎蕾', 20, 1, 2, '17755908510');
INSERT INTO `student` VALUES (211, '喻千山', 22, 1, 3, '17755908510');
INSERT INTO `student` VALUES (212, '舜迈', 21, 2, 3, '17755908510');
INSERT INTO `student` VALUES (213, '镜向雪', 22, 2, 8, '17755908510');
INSERT INTO `student` VALUES (214, '合宜欣', 20, 3, 6, '17755908510');
INSERT INTO `student` VALUES (215, '问绿竹', 19, 1, 1, '17755908510');
INSERT INTO `student` VALUES (216, '锺富', 19, 1, 7, '17755908510');
INSERT INTO `student` VALUES (217, '盈罗绮', 19, 2, 5, '17755908510');
INSERT INTO `student` VALUES (218, '萧冷之', 22, 1, 9, '17755908510');
INSERT INTO `student` VALUES (219, '全俊材', 20, 3, 7, '17755908510');
INSERT INTO `student` VALUES (220, '桥俊发', 22, 2, 2, '17755908510');
INSERT INTO `student` VALUES (221, '朱天亦', 18, 1, 6, '17755908510');
INSERT INTO `student` VALUES (222, '忻高邈', 20, 4, 1, '17755908510');
INSERT INTO `student` VALUES (223, '斋雅韵', 20, 2, 4, '17755908510');
INSERT INTO `student` VALUES (224, '后淑贞', 22, 1, 6, '17755908510');
INSERT INTO `student` VALUES (225, '业清芬', 22, 1, 3, '17755908510');
INSERT INTO `student` VALUES (226, '闽瓃', 21, 3, 4, '17755908510');
INSERT INTO `student` VALUES (227, '禚文昌', 19, 3, 9, '17755908510');
INSERT INTO `student` VALUES (228, '庹鸿志', 18, 1, 8, '17755908510');
INSERT INTO `student` VALUES (229, '老骏', 18, 2, 3, '17755908510');
INSERT INTO `student` VALUES (230, '弘天空', 22, 4, 1, '17755908510');
INSERT INTO `student` VALUES (231, '势驰颖', 21, 2, 6, '17755908510');
INSERT INTO `student` VALUES (232, '理逸美', 18, 1, 2, '17755908510');
INSERT INTO `student` VALUES (233, '俞航', 19, 4, 6, '17755908510');
INSERT INTO `student` VALUES (234, '潘盼波', 18, 2, 8, '17755908510');
INSERT INTO `student` VALUES (235, '乌孙翠梅', 22, 4, 3, '17755908510');
INSERT INTO `student` VALUES (236, '古曦之', 19, 4, 8, '17755908510');
INSERT INTO `student` VALUES (237, '索晓瑶', 19, 3, 8, '17755908510');
INSERT INTO `student` VALUES (238, '伏甜', 19, 3, 5, '17755908510');
INSERT INTO `student` VALUES (239, '钟离映雁', 19, 4, 2, '17755908510');
INSERT INTO `student` VALUES (240, '鄞听荷', 18, 1, 8, '17755908510');
INSERT INTO `student` VALUES (241, '琦代玉', 19, 1, 7, '17755908510');
INSERT INTO `student` VALUES (242, '牟星雨', 21, 4, 3, '17755908510');
INSERT INTO `student` VALUES (243, '军文瑶', 18, 1, 1, '17755908510');
INSERT INTO `student` VALUES (244, '诸葛弘懿', 18, 1, 1, '17755908510');
INSERT INTO `student` VALUES (245, '祭骊英', 19, 4, 6, '17755908510');
INSERT INTO `student` VALUES (246, '旷斯', 19, 1, 6, '17755908510');
INSERT INTO `student` VALUES (247, '乌雅熙', 18, 2, 7, '17755908510');
INSERT INTO `student` VALUES (248, '仁明凝', 20, 4, 8, '17755908510');
INSERT INTO `student` VALUES (249, '顾振海', 22, 3, 6, '17755908510');
INSERT INTO `student` VALUES (250, '任秋翠', 19, 2, 2, '17755908510');
INSERT INTO `student` VALUES (251, '权从云', 19, 2, 5, '17755908510');
INSERT INTO `student` VALUES (252, '蒋濡', 21, 1, 9, '17755908510');
INSERT INTO `student` VALUES (253, '呼雨安', 18, 4, 5, '17755908510');
INSERT INTO `student` VALUES (254, '遇海融', 22, 2, 6, '17755908510');
INSERT INTO `student` VALUES (255, '肖英才', 19, 1, 5, '17755908510');
INSERT INTO `student` VALUES (256, '拓跋骊萍', 22, 4, 6, '17755908510');
INSERT INTO `student` VALUES (257, '佟佳俊悟', 21, 1, 7, '17755908510');
INSERT INTO `student` VALUES (258, '卞硕', 19, 2, 9, '17755908510');
INSERT INTO `student` VALUES (259, '阿朗', 20, 4, 3, '17755908510');
INSERT INTO `student` VALUES (260, '常叶芳', 22, 2, 3, '17755908510');
INSERT INTO `student` VALUES (261, '端怀玉', 18, 3, 9, '17755908510');
INSERT INTO `student` VALUES (262, '皇含桃', 20, 4, 2, '17755908510');
INSERT INTO `student` VALUES (263, '帖梦菲', 21, 4, 4, '17755908510');
INSERT INTO `student` VALUES (264, '用君昊', 18, 2, 6, '17755908510');
INSERT INTO `student` VALUES (265, '聊曼容', 19, 4, 9, '17755908510');
INSERT INTO `student` VALUES (266, '司徒平卉', 19, 1, 9, '17755908510');
INSERT INTO `student` VALUES (267, '禄米', 18, 3, 3, '17755908510');
INSERT INTO `student` VALUES (268, '苍诗珊', 21, 2, 7, '17755908510');
INSERT INTO `student` VALUES (269, '皋迎丝', 18, 2, 6, '17755908510');
INSERT INTO `student` VALUES (270, '璩清晖', 20, 1, 9, '17755908510');
INSERT INTO `student` VALUES (271, '其善', 20, 4, 8, '17755908510');
INSERT INTO `student` VALUES (272, '阚晶辉', 19, 1, 8, '17755908510');
INSERT INTO `student` VALUES (273, '达璞玉', 21, 4, 5, '17755908510');
INSERT INTO `student` VALUES (274, '吕盼柳', 22, 2, 8, '17755908510');
INSERT INTO `student` VALUES (275, '邗君', 19, 2, 3, '17755908510');
INSERT INTO `student` VALUES (276, '黎念柏', 21, 4, 5, '17755908510');
INSERT INTO `student` VALUES (277, '梁雨凝', 21, 3, 8, '17755908510');
INSERT INTO `student` VALUES (278, '诺君昊', 22, 1, 1, '17755908510');
INSERT INTO `student` VALUES (279, '贰和暖', 21, 2, 9, '17755908510');
INSERT INTO `student` VALUES (280, '剧春华', 19, 3, 2, '17755908510');
INSERT INTO `student` VALUES (281, '彤人', 21, 3, 5, '17755908510');
INSERT INTO `student` VALUES (282, '壬晖', 21, 4, 6, '17755908510');
INSERT INTO `student` VALUES (283, '利和', 20, 3, 5, '17755908510');
INSERT INTO `student` VALUES (284, '富宏伟', 22, 4, 4, '17755908510');
INSERT INTO `student` VALUES (285, '訾茹', 20, 4, 4, '17755908510');
INSERT INTO `student` VALUES (286, '官馨蓉', 18, 2, 9, '17755908510');
INSERT INTO `student` VALUES (287, '泣语梦', 20, 2, 8, '17755908510');
INSERT INTO `student` VALUES (288, '谷梁元思', 19, 1, 3, '17755908510');
INSERT INTO `student` VALUES (289, '孛和昶', 22, 1, 3, '17755908510');
INSERT INTO `student` VALUES (290, '友嘉良', 19, 3, 1, '17755908510');
INSERT INTO `student` VALUES (291, '虎晴曦', 19, 4, 5, '17755908510');
INSERT INTO `student` VALUES (292, '丹怀薇', 21, 3, 3, '17755908510');
INSERT INTO `student` VALUES (293, '羊舌光赫', 22, 4, 9, '17755908510');
INSERT INTO `student` VALUES (294, '董山槐', 19, 2, 9, '17755908510');
INSERT INTO `student` VALUES (295, '邹代卉', 21, 3, 1, '17755908510');
INSERT INTO `student` VALUES (296, '务胜', 21, 4, 7, '17755908510');
INSERT INTO `student` VALUES (297, '洪书', 21, 3, 2, '17755908510');
INSERT INTO `student` VALUES (298, '夹谷舒怀', 19, 4, 9, '17755908510');
INSERT INTO `student` VALUES (299, '步畅然', 18, 4, 8, '17755908510');
INSERT INTO `student` VALUES (300, '苟巍奕', 21, 1, 3, '17755908510');
INSERT INTO `student` VALUES (301, '习寄文', 22, 3, 4, '17755908510');
INSERT INTO `student` VALUES (302, '侨启', 21, 3, 4, '17755908510');
INSERT INTO `student` VALUES (303, '弭妍雅', 19, 1, 3, '17755908510');
INSERT INTO `student` VALUES (304, '符诗霜', 22, 3, 3, '17755908510');
INSERT INTO `student` VALUES (305, '朋晔晔', 21, 1, 7, '17755908510');
INSERT INTO `student` VALUES (306, '针建本', 19, 4, 1, '17755908510');
INSERT INTO `student` VALUES (307, '容进', 22, 2, 9, '17755908510');
INSERT INTO `student` VALUES (308, '佴安祯', 21, 2, 7, '17755908510');
INSERT INTO `student` VALUES (309, '謇梦蕊', 20, 3, 2, '17755908510');
INSERT INTO `student` VALUES (310, '章琳', 22, 2, 6, '17755908510');
INSERT INTO `student` VALUES (311, '真熠彤', 21, 2, 4, '17755908510');
INSERT INTO `student` VALUES (312, '聂淑婉', 19, 3, 1, '17755908510');
INSERT INTO `student` VALUES (313, '速水之', 21, 1, 5, '17755908510');
INSERT INTO `student` VALUES (314, '进昌淼', 22, 1, 1, '17755908510');
INSERT INTO `student` VALUES (315, '隐心思', 22, 4, 8, '17755908510');
INSERT INTO `student` VALUES (316, '赫木', 22, 3, 2, '17755908510');
INSERT INTO `student` VALUES (317, '司马苇', 22, 1, 1, '17755908510');
INSERT INTO `student` VALUES (318, '定骊燕', 18, 2, 2, '17755908510');
INSERT INTO `student` VALUES (319, '路怡和', 20, 2, 6, '17755908510');
INSERT INTO `student` VALUES (320, '卢金玉', 19, 2, 8, '17755908510');
INSERT INTO `student` VALUES (321, '厉骏琛', 20, 4, 8, '17755908510');
INSERT INTO `student` VALUES (322, '宝天翰', 18, 4, 8, '17755908510');
INSERT INTO `student` VALUES (323, '戈慧艳', 21, 2, 5, '17755908510');
INSERT INTO `student` VALUES (324, '幸绿海', 19, 3, 2, '17755908510');
INSERT INTO `student` VALUES (325, '沈本', 18, 1, 8, '17755908510');
INSERT INTO `student` VALUES (326, '黄南', 21, 4, 6, '17755908510');
INSERT INTO `student` VALUES (327, '段庸', 22, 4, 4, '17755908510');
INSERT INTO `student` VALUES (328, '谏侠骞', 22, 3, 1, '17755908510');
INSERT INTO `student` VALUES (329, '泷澍', 20, 1, 7, '17755908510');
INSERT INTO `student` VALUES (330, '凤春芳', 21, 3, 1, '17755908510');
INSERT INTO `student` VALUES (331, '崇央', 20, 4, 2, '17755908510');
INSERT INTO `student` VALUES (332, '布秋月', 21, 1, 6, '17755908510');
INSERT INTO `student` VALUES (333, '镇新霁', 18, 1, 7, '17755908510');
INSERT INTO `student` VALUES (334, '北诗珊', 21, 2, 3, '17755908510');
INSERT INTO `student` VALUES (335, '愈水芸', 22, 2, 5, '17755908510');
INSERT INTO `student` VALUES (336, '蹇曼彤', 22, 3, 6, '17755908510');
INSERT INTO `student` VALUES (337, '马佳如冰', 19, 3, 9, '17755908510');
INSERT INTO `student` VALUES (338, '谢澄', 18, 3, 9, '17755908510');
INSERT INTO `student` VALUES (339, '依曼云', 19, 2, 4, '17755908510');
INSERT INTO `student` VALUES (340, '板新美', 22, 2, 8, '17755908510');
INSERT INTO `student` VALUES (341, '巧承平', 22, 4, 1, '17755908510');
INSERT INTO `student` VALUES (342, '植骊雪', 20, 3, 7, '17755908510');
INSERT INTO `student` VALUES (343, '佘思菱', 22, 2, 2, '17755908510');
INSERT INTO `student` VALUES (344, '霜弘扬', 21, 4, 6, '17755908510');
INSERT INTO `student` VALUES (345, '革庆生', 19, 2, 7, '17755908510');
INSERT INTO `student` VALUES (346, '刚嘉祥', 21, 4, 7, '17755908510');
INSERT INTO `student` VALUES (347, '仙昆峰', 20, 2, 3, '17755908510');
INSERT INTO `student` VALUES (348, '通奇水', 19, 4, 1, '17755908510');
INSERT INTO `student` VALUES (349, '营恨桃', 19, 1, 4, '17755908510');
INSERT INTO `student` VALUES (350, '祝颐', 21, 4, 2, '17755908510');
INSERT INTO `student` VALUES (351, '碧舒方', 19, 4, 8, '17755908510');
INSERT INTO `student` VALUES (352, '寒依云', 21, 2, 7, '17755908510');
INSERT INTO `student` VALUES (353, '爱星文', 19, 4, 9, '17755908510');
INSERT INTO `student` VALUES (354, '稽静芙', 21, 1, 9, '17755908510');
INSERT INTO `student` VALUES (355, '钦远骞', 19, 4, 9, '17755908510');
INSERT INTO `student` VALUES (356, '姬海冬', 19, 4, 2, '17755908510');
INSERT INTO `student` VALUES (357, '雀玉轩', 21, 1, 7, '17755908510');
INSERT INTO `student` VALUES (358, '盛听安', 22, 3, 9, '17755908510');
INSERT INTO `student` VALUES (359, '景婉容', 22, 1, 3, '17755908510');
INSERT INTO `student` VALUES (360, '登卿', 21, 2, 9, '17755908510');
INSERT INTO `student` VALUES (361, '才秀洁', 18, 1, 6, '17755908510');
INSERT INTO `student` VALUES (362, '程森丽', 20, 2, 6, '17755908510');
INSERT INTO `student` VALUES (363, '脱香柏', 18, 3, 2, '17755908510');
INSERT INTO `student` VALUES (364, '随冬梅', 20, 2, 8, '17755908510');
INSERT INTO `student` VALUES (365, '吉莹莹', 20, 1, 3, '17755908510');
INSERT INTO `student` VALUES (366, '允君', 21, 1, 2, '17755908510');
INSERT INTO `student` VALUES (367, '邱雅懿', 21, 2, 3, '17755908510');
INSERT INTO `student` VALUES (368, '豆香梅', 19, 1, 1, '17755908510');
INSERT INTO `student` VALUES (369, '焦晓莉', 20, 3, 3, '17755908510');
INSERT INTO `student` VALUES (370, '康芷云', 19, 4, 6, '17755908510');

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `username` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `password` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `auth` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`username`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('123', '123', 'admin');
INSERT INTO `user` VALUES ('暮晨', '123456', 'admin');

SET FOREIGN_KEY_CHECKS = 1;
