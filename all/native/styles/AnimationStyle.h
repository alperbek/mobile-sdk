/*
 * Copyright (c) 2016 CartoDB. All rights reserved.
 * Copying and using this code is allowed only according
 * to license terms, as given in https://cartodb.com/terms/
 */

#ifndef _CARTO_ANIMATIONSTYLE_H_
#define _CARTO_ANIMATIONSTYLE_H_

namespace carto {

    namespace AnimationType {
        /**
         * Possible animation types.
         */
        enum AnimationType {
            /**
             * No animation is applied.
             */
            ANIMATION_TYPE_NONE,
            /**
             * Step transition is applied at the middle of the animation.
             */
            ANIMATION_TYPE_STEP,
            /**
             * Linear transition is used for animation.
             */
            ANIMATION_TYPE_LINEAR,
            /**
             * Smooth transition with 2nd order continuity is used for animation.
             */
            ANIMATION_TYPE_SMOOTHSTEP,
            /**
             * Spring-like transition is used for animation.
             */
            ANIMATION_TYPE_SPRING
        };
    };
    
    /**
     * A class describing animation effect.
     */
    class AnimationStyle {
    public:
        /**
         * Constructs an AnimationStyle object from various parameters. Instantiating the object directly is
         * not recommended, AnimationStyleBuilder should be used instead.
         * @param relativeSpeed The relative speed of the animation. 1.0 is the default.
         * @param fadeAnimationType The fade/blending animation type.
         * @param sizeAnimationType The element size animation type.
         */
        AnimationStyle(float relativeSpeed, AnimationType::AnimationType fadeAnimationType, AnimationType::AnimationType sizeAnimationType);
        virtual ~AnimationStyle();
    
        /**
         * Returns the relative speed of the animation.
         * @return The relative speed of the animation (1.0 corresponds to the default speed).
         */
        float getRelativeSpeed() const;

        /**
         * Returns the fade animation type.
         * @return The type of the fade animation.
         */
        AnimationType::AnimationType getFadeAnimationType() const;

        /**
         * Returns the size-related animation type.
         * @return The type of the size-related animation.
         */
        AnimationType::AnimationType getSizeAnimationType() const;

        /**
         * Returns animation transition value based on animation type.
         * @param animationType Type of the animation.
         * @param t The input value between 0..1.
         * @return The transition value, always non-negative. For t=1, it is always 1. 
         */
        static float CalculateTransition(AnimationType::AnimationType animationType, float t);
        
    protected:
        float _relativeSpeed;
        
        AnimationType::AnimationType _fadeAnimationType;
        AnimationType::AnimationType _sizeAnimationType;
    };
    
}

#endif
