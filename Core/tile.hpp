class cTile
{
	private:
		SDL_Texture *texture;
		bool water;
		bool slow;//for terrain that limits movements
	public:
		void OnRender();
		bool isSlow();
		bool isWater();
}