--ccgui helper funciton
ccgui = {}

function ccgui.nodeToEditBox(node)
	local edit = EditBox:create("edit")
	local parent = node:getParentWidget()
	local x, y = node:getPosition()
	edit:setPosition(CCPoint(x,y))
	edit:setContentSize(node:getContentSize())
	edit:setTag(node:getTag())
	parent:addWidget(edit)
	parent:removeWidget(node)
	return edit
end

function ccgui.nodeToItemBox(scroll, itembox)
end

function ccgui.nodeToProgress(scroll, progressBar)
end




