/*
 * Gearboy - Nintendo Game Boy Emulator
 * Copyright (C) 2012  Ignacio Sanchez

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/ 
 * 
 */

#ifndef VIDEO_H
#define	VIDEO_H

#include "definitions.h"

class Memory;
class Processor;

class Video
{
public:
    Video(Memory* pMemory, Processor* pProcessor);
    ~Video();
    void Init();
    void Reset(bool bCGB);
    bool Tick(u8 clockCycles, GB_Color* pColorFrameBuffer);
    void EnableScreen();
    void DisableScreen();
    bool IsScreenEnabled() const;
    const u8* GetFrameBuffer() const;
    void SetColorPalette(bool background, u8 value);
private:
    void ScanLine(int line);
    void RenderBG(int line);
    void RenderWindow(int line);
    void RenderSprites(int line);
    void UpdateStatRegister();
    void UpdateLYRegister();
    GB_Color ConvertTo8BitColor(GB_Color color);
private:
    Memory* m_pMemory;
    Processor* m_pProcessor;
    u8* m_pFrameBuffer;
    GB_Color* m_pColorFrameBuffer;
    int* m_pSpriteXCacheBuffer;
    u8* m_pColorCacheBuffer;
    int m_iStatusMode;
    int m_iStatusModeCounter;
    int m_iStatusModeCounterAux;
    int m_iStatusModeLYCounter;
    int m_iScreenEnableDelayCycles;
    bool m_bScreenEnabled;
    bool m_bCGB;
    GB_Color m_CGBSpritePalettes[8][4];
    GB_Color m_CGBBackgroundPalettes[8][4];
};

#endif	/* VIDEO_H */
