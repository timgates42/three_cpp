#ifndef THREE_DATA_TEXTURE_HPP
#define THREE_DATA_TEXTURE_HPP

#include <three/common.hpp>

#include <three/textures/texture.hpp>

namespace three{

class DataTexture : public Texture {

public:

	typedef std::shared_ptr<DataTexture> Ptr;

	static Ptr create( std::vector<unsigned char> data, float width, float height, const TextureDesc& desc ) {

		return make_shared<DataTexture>( data, width, height, desc );

	};

	Image image;

	virtual enums::TextureType type() const {

		return enums::DataTexture;
		
	}

  THREE_TODO("clone")
	
protected:

	DataTexture( std::vector<unsigned char> data, float width, float height, const TextureDesc& desc )
		: Texture( desc ) {

			image = Image( data, width, height );

	}

};

}

#endif // THREE_DATA_TEXTURE_HPP