#pragma once

#include "ppsspp_config.h"

#include "Common/UI/UIScreen.h"
#include "Core/ConfigValues.h"
#include "UI/MiscScreens.h"

class TabbedUIDialogScreenWithGameBackground : public UIDialogScreenWithGameBackground {
public:
	TabbedUIDialogScreenWithGameBackground(const Path &gamePath) : UIDialogScreenWithGameBackground(gamePath) {}

	UI::LinearLayout *AddTab(const char *tag, const std::string &title, bool isSearch = false);
	void CreateViews() override;


protected:
	// Load data and define your tabs here.
	virtual void PreCreateViews() {}
	virtual void CreateTabs() = 0;
	virtual bool ShowSearchControls() { return true; }

	void RecreateViews() override;

	SettingInfoMessage *settingInfo_ = nullptr;

private:
	void sendMessage(const char *message, const char *value) override;
	void ApplySearchFilter();

	UI::TabHolder *tabHolder_ = nullptr;
	std::vector<UI::LinearLayout *> settingTabContents_;
	std::vector<UI::TextView *> settingTabFilterNotices_;
	UI::Choice *clearSearchChoice_ = nullptr;
	UI::TextView *noSearchResults_ = nullptr;
	// If we recreate the views while this is active we show it again
	std::string oldSettingInfo_;
	std::string searchFilter_;
};
