/*
 * Copyright (C) 2011-2012 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SKYFIRE_MOVESPLINEFLAG_H
#define SKYFIRE_MOVESPLINEFLAG_H

#include "MovementTypedefs.h"

#include <string>

namespace Movement
{
#if defined( __GNUC__ )
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

    class MoveSplineFlag
    {
    public:
        enum eFlags{
            None         = 0x00000000,
                                                 // x00-xFF(first byte) used as animation Ids storage in pair with Animation flag
            Done         = 0x00000100,
            Falling      = 0x00000200,           // Affects elevation computation, can't be combined with Parabolic flag
            No_Spline    = 0x00000400,
            Parabolic    = 0x00000800,           // Affects elevation computation, can't be combined with Falling flag
            Walkmode     = 0x00001000,
            Flying       = 0x00002000,           // Smooth movement(Catmullrom interpolation mode), flying animation
            OrientationFixed = 0x00004000,       // Model orientation fixed
            Final_Point  = 0x00008000,
            Final_Target = 0x00010000,
            Final_Angle  = 0x00020000,
            Catmullrom   = 0x00040000,           // Used Catmullrom interpolation mode
            Cyclic       = 0x00080000,           // Movement by cycled spline
            Enter_Cycle  = 0x00100000,           // Everytimes appears with cyclic flag in monster move packet, erases first spline vertex after first cycle done
            Animation    = 0x00200000,           // Plays animation after some time passed
            Frozen       = 0x00400000,           // Will never arrive
            Transport    = 0x00800000,
            Exit_Vehicle = 0x01000000,
            Unknown26     = 0x02000000,
            Unknown27     = 0x04000000,
            OrientationInversed = 0x08000000,
            UsePathSmoothing    = 0x10000000,
            Animation2    = 0x20000000,
            UnCompressedPath    = 0x40000000,
            Unknown32    = 0x80000000,

            // Masks
            Mask_Final_Facing = Final_Point | Final_Target | Final_Angle,
            // animation ids stored here, see AnimType enum, used with Animation flag
            Mask_Animations = 0xFF,
            // flags that shouldn't be appended into SMSG_MONSTER_MOVE\SMSG_MONSTER_MOVE_TRANSPORT packet, should be more probably
            Mask_No_Monster_Move = Mask_Final_Facing | Mask_Animations | Done,
            // CatmullRom interpolation mode used
            Mask_CatmullRom = Flying | Catmullrom,
            // Unused, not supported flags
            Mask_Unused = No_Spline|Enter_Cycle|Frozen|Transport|Exit_Vehicle|Unknown26|Unknown27,
        };

        inline uint32& raw() { return (uint32&)*this;}
        inline const uint32& raw() const { return (const uint32&)*this;}

        MoveSplineFlag() { raw() = 0; }
        MoveSplineFlag(uint32 f) { raw() = f; }
        MoveSplineFlag(const MoveSplineFlag& f) { raw() = f.raw(); }

        // Constant interface

        bool isSmooth() const { return raw() & Mask_CatmullRom;}
        bool isLinear() const { return !isSmooth();}
        bool isFacing() const { return raw() & Mask_Final_Facing;}

        uint8 getAnimationId() const { return animId;}
        bool hasAllFlags(uint32 f) const { return (raw() & f) == f;}
        bool hasFlag(uint32 f) const { return (raw() & f) != 0;}
        uint32 operator & (uint32 f) const { return (raw() & f);}
        uint32 operator | (uint32 f) const { return (raw() | f);}
        std::string ToString() const;

        // Not constant interface

        void operator &= (uint32 f) { raw() &= f;}
        void operator |= (uint32 f) { raw() |= f;}

        void EnableAnimation(uint8 anim) { raw() = raw() & ~(Mask_Animations|Falling|Parabolic) | Animation|anim;}
        void EnableParabolic() { raw() = raw() & ~(Mask_Animations|Falling|Animation) | Parabolic;}
        void EnableFalling() { raw() = raw() & ~(Mask_Animations|Parabolic|Animation) | Falling;}
        void EnableFlying() { raw() = raw() & ~Catmullrom | Flying | UnCompressedPath | UsePathSmoothing | Unknown32 | Unknown26;}
        void EnableCatmullRom() { raw() = raw() & ~Flying | Catmullrom | UnCompressedPath | UsePathSmoothing | Unknown32 | Unknown26;}
        void EnableFacingPoint() { raw() = raw() & ~Mask_Final_Facing | Final_Point;}
        void EnableFacingAngle() { raw() = raw() & ~Mask_Final_Facing | Final_Angle;}
        void EnableFacingTarget() { raw() = raw() & ~Mask_Final_Facing | Final_Target;}

        uint8 animId       : 8;
        bool done          : 1;
        bool falling       : 1;
        bool no_spline     : 1;
        bool parabolic     : 1;
        bool walkmode      : 1;
        bool flying        : 1;
        bool orientationFixed : 1;
        bool final_point   : 1;
        bool final_target  : 1;
        bool final_angle   : 1;
        bool catmullrom    : 1;
        bool cyclic        : 1;
        bool enter_cycle   : 1;
        bool animation     : 1;
        bool frozen        : 1;
        bool transport     : 1;
        bool exit_vehicle  : 1;
        bool unknown26      : 1;
        bool unknown27      : 1;
        bool orientationInversed : 1;
        bool usePathSmoothing    : 1;
        bool animation2     : 1;
        bool unCompressedPath    : 1;
        bool unknown32     : 1;
    };
#if defined( __GNUC__ )
#pragma pack()
#else
#pragma pack(pop)
#endif
}

#endif // SKYFIRE_MOVESPLINEFLAG_H
