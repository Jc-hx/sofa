/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU General Public License as published by the Free  *
* Software Foundation; either version 2 of the License, or (at your option)   *
* any later version.                                                          *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for    *
* more details.                                                               *
*                                                                             *
* You should have received a copy of the GNU General Public License along     *
* with this program. If not, see <http://www.gnu.org/licenses/>.              *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include <iostream>
#include <sofa/config.h>
#include <sofa/geometry/init.h>

#include <iostream>

// ---------------------------------------------------------------------
// ---
// ---------------------------------------------------------------------
int main(int /*argc*/, char** argv)
{

    // Tests Geometry
    
    sofa::geometry::init();
    std::cout << "Is initialized : " << sofa::geometry::isInitialized() << std::endl;
    sofa::geometry::cleanup();
    std::cout << "SofaGeometryTest has been initialized." << std::endl;

    return 0;
}
