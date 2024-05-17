#pragma once



namespace tr {
	enum class ScreenSetMode {
		e640x480color16,
		e320x200color256,
		e640x480monochrome
	};

	struct InstanceInfos {
		tr::ScreenSetMode screenSetMode;
	};

	class Instance {
		public:
			Instance(const tr::InstanceInfos &infos);
			~Instance();

		private:
			tr::InstanceInfos m_infos;
	};

} // namespace tr
