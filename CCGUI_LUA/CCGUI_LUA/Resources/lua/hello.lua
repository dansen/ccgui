require("ccgui")

local function main()
    -- run
    local sceneGame = CCScene:create()

	local root = widget_manager_init(sceneGame,1)
	local ccb = CCBWidget:create("ccb","CCB/shop/ShopLayer.ccb")

	ccb:get("btnClose"):touchBegin(
		function(node, touch)
			ccb:removeFromParentAndCleanup(true)
		end
	)
	local box = ccb:get("scrollContent")
	tolua.cast(box, "ItemBox")

    for i=1,10 do 
        local item = CCBWidget:create("item"..i, "CCB/shop/DanyaoNode.ccb")
		item:setContentSize(CCSize(510,130))
        box:addItem(item)
    end
    
	local editNode = ccb:get("editBox")
	local editBox = ccgui.nodeToEditBox(editNode)
	print(editBox:getPosition())
	
	root:addWidget(ccb)
	
    CCDirector:sharedDirector():runWithScene(sceneGame)
end

main()
