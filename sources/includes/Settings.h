/****************************************************************************
 * Main developer, C# developing:                                           *
 * Copyright (C) 2014-2016 by Sergey Zheigurov                              *
 * Russia, Novy Urengoy                                                     *
 * zheigurov@gmail.com                                                      *
 *                                                                          *
 * C# to Qt portation, Linux developing                                     *
 * Copyright (C) 2015-2016 by Eduard Kalinowski                             *
 * Germany, Lower Saxony, Hanover                                           *
 * eduard_kalinowski@yahoo.de                                               *
 *                                                                          *
 * C# project CNC-controller-for-mk1                                        *
 * https://github.com/selenur/CNC-controller-for-mk1                        *
 *                                                                          *
 * The Qt project                                                           *
 * https://github.com/eduard-x/cnc-qt                                       *
 *                                                                          *
 * CNC-Qt is free software; may be distributed and/or modified under the    *
 * terms of the GNU General Public License version 3 as published by the    *
 * Free Software Foundation and appearing in the file LICENSE_GPLv3         *
 * included in the packaging of this file.                                  *
 *                                                                          *
 * This program is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU General Public License for more details.                             *
 *                                                                          *
 * You should have received a copy of the GNU Lesser General Public         *
 * License along with CNC-Qt. If not, see  http://www.gnu.org/licenses      *
 ****************************************************************************/


#ifndef SETTINGS_H
#define SETTINGS_H

#include "MainWindow.h"
#include "ui_Settings.h"

class cTranslator;
class MainWindow;



enum AxisNames { X = 0, Y, Z, A, B, C, U, V, W };


class axis
{
    public:
        axis(); // constructor
        float posMm();
        int posPulse(float posMm);

    public:
        float minVelo;
        float maxVelo;
        float acceleration;
        int   pulsePerMm;
        float actualPosmm;
        int   actualPosPulses;
        bool  invertDirection;
        bool  invertPulses;

        bool  useLimitMin; // set HW
        bool  useLimitMax; // set HW
        bool  invLimitMin; // set HW
        bool  invLimitMax; // set HW

        bool  actualLimitMax; // get from HW
        bool  actualLimitMin; // get from HW

        float startPos;
        bool  checkSoftLimits;

        float softLimitMax;
        float softLimitMin;
        float backlash;
        float workAreaMin;
        float workAreaMax;
        bool  enabled;
        float home;
        bool  wrong;
};


class Settings
{
    public:
        static axis coord[4]; // array of 4 axis for mk1
        static int splitsPerMm;
        static float maxLookaheadAngle;

        static QChar fromDecimalPoint;
        static QChar toDecimalPoint;
        //         QVector<axis> mk2[9]; // array of 9 axis for mk2

        //         static bool setSettings;
        //         static int  spindleMoveSpeed;
        //         static bool spindleEnabled;
        //         static bool mistEnabled;
        //         static bool fluidEnabled;
        //
        //         static bool Estop;

        // for virtual controller
        static bool DEMO_DEVICE;
};




class SettingsDialog : public QDialog, public Ui::SettingsDialog,  public cTranslator
{
        Q_OBJECT
    public:
        SettingsDialog(QWidget *parent = 0);

    private slots:
        void onSave();
        void onSelection(QListWidgetItem* it);

    private:
        void translateDialog();

    private:
        MainWindow* parent;
        mk1Controller *cnc;
};


#endif // SETTINGS_H
