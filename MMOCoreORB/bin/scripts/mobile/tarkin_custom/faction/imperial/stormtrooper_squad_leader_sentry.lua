stormtrooper_squad_leader_sentry = Creature:new {
	objectName = "",
	customName = "Stormtrooper Sentry Squad Leader",
	socialGroup = "imperial",
	faction = "imperial",
	level = 122,
	chanceHit = 40,
	damageMin = 745,
	damageMax = 1200,
	baseXp = 11577,
	baseHAM = 44000,
	baseHAMmax = 54000,
	armor = 0,
	resists = {55,45,80,30,0,0,30,45,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_stormtrooper_squad_leader_white_gold.iff"},
	lootGroups = {
		{
			groups = {
				{group = "color_crystals", chance = 100000},
				{group = "junk", chance = 4400000},
				{group = "rifles", chance = 550000},
				{group = "pistols", chance = 550000},
                		{group = "melee_weapons", chance = 550000},
                		{group = "carbines", chance = 550000},
				{group = "rebel_spire", chance = 1250000},
				{group = "clothing_attachments", chance = 1025000},
				{group = "armor_attachments", chance = 1025000}
			},
			lootChance = 3500000
		}						
	},
	weapons = {"stormtrooper_weapons"},
	conversationTemplate = "",
	attacks = merge(riflemanmaster,carbineermaster)
}

CreatureTemplates:addCreatureTemplate(stormtrooper_squad_leader_sentry, "stormtrooper_squad_leader_sentry")
