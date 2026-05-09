#pragma once
#include <scout.hpp>


namespace Scout {

	enum class TextureWrapMethod { Repeat, MirroredRepeat, ClampToEdge };
	enum class TextureMinFilter { Nearest, Linear, NearestMipmapNearest, LinearMipmapNearest, NearestMipmapLinear, LinearMipmapLinear };
	enum class TextureMagFilter { Nearest, Linear };
	enum class TextureFormat { RGB, RGBA };

	class Texture {

		private:
		
		unsigned int id;
		unsigned int width;
		unsigned int height;

		TextureWrapMethod wrapS;
		TextureWrapMethod wrapT;

		TextureMinFilter minFilter;
		TextureMagFilter magFilter;

		TextureFormat format;
		bool destroyed = false;
	
		public:

		Texture(unsigned char* data, unsigned int width, unsigned int height, TextureWrapMethod wrapS, TextureWrapMethod wrapT, TextureMinFilter minFilter, TextureMagFilter magFilter, TextureFormat format);
		virtual ~Texture();

		void enable(int index);


		unsigned int getId();
		unsigned int getWidth();
		unsigned int getHeight();

		TextureWrapMethod getWrapS();
		TextureWrapMethod getWrapT();
		TextureMinFilter getMinFilter();
		TextureMagFilter getMagFilter();

		TextureFormat getFormat();

		void destroy();


	};

}
