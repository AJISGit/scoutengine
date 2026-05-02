#include <texture.hpp>



Scout::Texture::Texture(unsigned char* data, unsigned int width, unsigned int height, Scout::TextureWrapMethod wrapS, Scout::TextureWrapMethod wrapT, Scout::TextureMinFilter minFilter, Scout::TextureMagFilter magFilter, Scout::TextureFormat format) {

	this->width = width;
	this->height = height;
	this->wrapS = wrapS;
	this->wrapT = wrapT;
	this->minFilter = minFilter;
	this->magFilter = magFilter;
	this->format = format;

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);


	switch (wrapS) {
		
		case Scout::TextureWrapMethod::Repeat:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			break;
		case Scout::TextureWrapMethod::MirroredRepeat:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
			break;
		case Scout::TextureWrapMethod::ClampToEdge:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			break;

	}


	switch (wrapT) {
		
		case Scout::TextureWrapMethod::Repeat:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			break;
		case Scout::TextureWrapMethod::MirroredRepeat:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
			break;
		case Scout::TextureWrapMethod::ClampToEdge:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			break;

	}


	switch (minFilter) {

		case Scout::TextureMinFilter::Nearest:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			break;
		case Scout::TextureMinFilter::Linear:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			break;
		case Scout::TextureMinFilter::NearestMipmapNearest:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
			break;
		case Scout::TextureMinFilter::NearestMipmapLinear:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
			break;
		case Scout::TextureMinFilter::LinearMipmapLinear:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			break;
		case Scout::TextureMinFilter::LinearMipmapNearest:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			break;

	}


	switch (magFilter) {

		case Scout::TextureMagFilter::Nearest:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			break;
		case Scout::TextureMagFilter::Linear:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			break;

	}

	
	int texInternalFormat;
	unsigned int texFormat;


	switch (format) {

		case Scout::TextureFormat::RGB:
			texInternalFormat = GL_RGB;
			texFormat = GL_RGB;
			break;
		case Scout::TextureFormat::RGBA:
			texInternalFormat = GL_RGBA;
			texFormat = GL_RGBA;
			break;

	}


	glTexImage2D(GL_TEXTURE_2D, 0, texInternalFormat, width, height, 0, texFormat, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

}


Scout::Texture::~Texture() {
	glDeleteTextures(1, &id);
}


unsigned int Scout::Texture::getId() {
	return id;
}


unsigned int Scout::Texture::getWidth() {
	return width;
}


unsigned int Scout::Texture::getHeight() {
	return height;
}


Scout::TextureWrapMethod Scout::Texture::getWrapS() {
	return wrapS;
}


Scout::TextureWrapMethod Scout::Texture::getWrapT() {
	return wrapT;
}


Scout::TextureMinFilter Scout::Texture::getMinFilter() {
	return minFilter;
}


Scout::TextureMagFilter Scout::Texture::getMagFilter() {
	return magFilter;
}


Scout::TextureFormat Scout::Texture::getFormat() {
	return format;
}


void Scout::Texture::enable(int index) {
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, getId());
}

