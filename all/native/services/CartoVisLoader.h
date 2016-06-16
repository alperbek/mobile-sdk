/*
 * Copyright (c) 2016 CartoDB. All rights reserved.
 * Copying and using this code is allowed only according
 * to license terms, as given in https://cartodb.com/terms/
 */

#ifndef _CARTO_CARTOVISLOADER_H_
#define _CARTO_CARTOVISLOADER_H_

#include "core/Variant.h"
#include "components/DirectorPtr.h"

#include <memory>
#include <mutex>
#include <string>

#include <boost/optional.hpp>

#include <picojson/picojson.h>

namespace carto {
    class AssetPackage;
    class Layer;
    class BaseMapView;
    class CartoMapsService;
    class CartoVisBuilder;

    class CartoVisLoader {
    public:
        CartoVisLoader();
        virtual ~CartoVisLoader();

        bool isDefaultVectorLayerMode() const;
        void setDefaultVectorLayerMode(bool enabled);

        std::shared_ptr<AssetPackage> getVectorTileAssetPackage() const;
        void setVectorTileAssetPackage(const std::shared_ptr<AssetPackage>& assetPackage);

        bool loadVis(const std::shared_ptr<CartoVisBuilder>& builder, const std::string& visURL) const;

    private:
        struct LayerInfo {
            std::shared_ptr<Layer> layer;
            picojson::object attributes;

            LayerInfo(const std::shared_ptr<Layer>& layer, const picojson::object& attributes) : layer(layer), attributes(attributes) { }
        };

        static void readLayerAttributes(picojson::object& attributes, const picojson::value& options);
        
        void configureMapsService(CartoMapsService& mapsService, const picojson::value& options) const;
        
        void configureLayerInteractivity(Layer& layer, const picojson::value& options) const;

        void createLayers(const std::shared_ptr<CartoVisBuilder>& builder, const picojson::value& layerConfig) const;

        boost::optional<LayerInfo> createTiledLayer(const picojson::value& options) const;
        boost::optional<LayerInfo> createTorqueLayer(const picojson::value& options, const picojson::value& legend) const;
        std::vector<LayerInfo> createNamedLayers(const picojson::value& options) const;
        std::vector<LayerInfo> createLayerGroup(const picojson::value& options, const picojson::value& infoWindow) const;

        bool _defaultVectorLayerMode;
        std::shared_ptr<AssetPackage> _vectorTileAssetPackage;

        mutable std::recursive_mutex _mutex;
    };

}

#endif