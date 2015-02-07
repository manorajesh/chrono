// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Class that renders the text and other UI elements
// Authors: Hammad Mazhar
// =============================================================================

#include <iostream>
#include "chrono_opengl/UI/ChOpenGLHUD.h"
#include "chrono_opengl/ChOpenGLMaterials.h"
#include <glm/gtc/type_ptr.hpp>

// Includes that are generated at compile time
#include "resources/text_frag.h"
#include "resources/text_vert.h"

using namespace glm;
using namespace chrono::opengl;

ChOpenGLHUD::ChOpenGLHUD() : ChOpenGLBase() { spacing = 0.055; }

bool ChOpenGLHUD::Initialize() {
  if (this->GLReturnedError("ChOpenGLHUD::Initialize - on entry"))
    return false;

  if (!font_shader.InitializeStrings("text", text_vert, text_frag)) {
    return 0;
  }

  text.Initialize(text_mat, & font_shader);

  return true;
}
void ChOpenGLHUD::Update(const glm::ivec2& window_size, const float& dpi) {

  sx = (2 * dpi / 147.782) / window_size.x;
  sy = (2 * dpi / 147.782) / window_size.y;
}

void ChOpenGLHUD::TakeDown() {

  font_shader.TakeDown();
  text.TakeDown();
}

void ChOpenGLHUD::DrawHelp() {
  text.Update();

  text.Render("Press h to exit help", -.95, 0.925 - spacing * 0, sx, sy);
  text.Render("W: Forward", -.95, 0.925 - spacing * 1, sx, sy);
  text.Render("A: Strafe Left", -.95, 0.925 - spacing * 2, sx, sy);
  text.Render("S: Back", -.95, 0.925 - spacing * 3, sx, sy);
  text.Render("D: Strafe Right", -.95, 0.925 - spacing * 4, sx, sy);
  text.Render("Q: Down", -.95, 0.925 - spacing * 5, sx, sy);
  text.Render("E: Up", -.95, 0.925 - spacing * 6, sx, sy);

  text.Render("Mouse Look (Click and hold left mouse button)", -.95, 0.925 - spacing * 7, sx, sy);

  text.Render("1: Point Cloud (default)", -.95, 0.925 - spacing * 9, sx, sy);
  text.Render("2: Wireframe (slow)", -.95, 0.925 - spacing * 10, sx, sy);
  text.Render("3: Solid", -.95, 0.925 - spacing * 11, sx, sy);

  text.Render("C: Show/Hide Contacts (DVI only)", -.95, 0.925 - spacing * 13, sx, sy);

  text.Render("Space: Pause Simulation (not rendering)", -.95, 0.925 - spacing * 15, sx, sy);
  text.Render("P: Pause Rendering (not simulating)", -.95, 0.925 - spacing * 16, sx, sy);
  text.Render(".: Single Step ", -.95, 0.925 - spacing * 18, sx, sy);
  text.Render("B: Enable/Disable AABB ", -.95, 0.925 - spacing * 20, sx, sy);

  text.Render("Escape: Exit ", -.95, 0.925 - spacing * 30, sx, sy);

  text.Draw();
}
void ChOpenGLHUD::DrawStats() {
//
//  sprintf(buffer, "Press h for help");
//  text.Render(buffer, 0, 0.925, sx, sy);
//
//  sprintf(buffer, "TIME:  %04f  | %04f", physics_system->GetChTime(), simulation_h);
//  text.Render(buffer, -.95, 0.925, sx, sy);
//  sprintf(buffer, "Camera Pos :  [%04f, %04f, %04f]", render_camera.camera_position.x, render_camera.camera_position.y, render_camera.camera_position.z);
//  text.Render(buffer, -.95, 0.925 - spacing * 1, sx, sy);
//  sprintf(buffer, "Camera Look:  [%04f, %04f, %04f]", render_camera.camera_look_at.x, render_camera.camera_look_at.y, render_camera.camera_look_at.z);
//  text.Render(buffer, -.95, 0.925 - spacing * 2, sx, sy);
//  sprintf(buffer, "Camera Up  :  [%04f, %04f, %04f]", render_camera.camera_up.x, render_camera.camera_up.y, render_camera.camera_up.z);
//  text.Render(buffer, -.95, 0.925 - spacing * 3, sx, sy);
//
//  sprintf(buffer, "SOLVER INFO");
//  text.Render(buffer, .6, 0.925 - spacing * 6, sx, sy);
//
//  double iters = ((ChLcpIterativeSolver*)(physics_system->GetLcpSolverSpeed()))->GetTotalIterations();
//  if (iters > 0) {
//    double residual = ((ChLcpIterativeSolver*)(physics_system->GetLcpSolverSpeed()))->GetViolationHistory().back();
//    double dlambda = ((ChLcpIterativeSolver*)(physics_system->GetLcpSolverSpeed()))->GetDeltalambdaHistory().back();
//
//    sprintf(buffer, "ITERS    %04d", int(iters));
//    text.Render(buffer, .6, 0.925 - spacing * 7, sx, sy);
//    sprintf(buffer, "RESIDUAL %04f", residual);
//    text.Render(buffer, .6, 0.925 - spacing * 8, sx, sy);
//    sprintf(buffer, "CORRECT  %04f", dlambda);
//    text.Render(buffer, .6, 0.925 - spacing * 9, sx, sy);
//  } else {
//    sprintf(buffer, "ITERS    %04d", 0);
//    text.Render(buffer, .6, 0.925 - spacing * 7, sx, sy);
//    sprintf(buffer, "RESIDUAL %04f", 0);
//    text.Render(buffer, .6, 0.925 - spacing * 8, sx, sy);
//    sprintf(buffer, "CORRECT  %04f", 0);
//    text.Render(buffer, .6, 0.925 - spacing * 9, sx, sy);
//  }
//
//  int num_bodies = (physics_system->GetNbodiesTotal() + physics_system->GetNphysicsItems());
//  int num_contacts = ((ChSystemParallel*)physics_system)->GetNcontacts();
//  int average_contacts_per_body = 0;
//  if (num_bodies > 0) {
//    average_contacts_per_body = num_contacts / num_bodies;
//  }
//  sprintf(buffer, "MODEL INFO");
//  text.Render(buffer, .6, 0.925 - spacing * 0, sx, sy);
//  sprintf(buffer, "BODIES     %04d", num_bodies);
//  text.Render(buffer, .6, 0.925 - spacing * 1, sx, sy);
//  if (ChSystemParallelDVI* parallel_sys = dynamic_cast<ChSystemParallelDVI*>(physics_system)) {
//    sprintf(buffer, "AABB       %04d", parallel_sys->data_manager->host_data.aabb_rigid.size() / 2);
//    text.Render(buffer, .6, 0.925 - spacing * 2, sx, sy);
//  }
//  sprintf(buffer, "CONTACTS   %04d", num_contacts);
//  text.Render(buffer, .6, 0.925 - spacing * 3, sx, sy);
//  sprintf(buffer, "AVGCONPB   %04d", average_contacts_per_body);
//  text.Render(buffer, .6, 0.925 - spacing * 4, sx, sy);
//
//  sprintf(buffer, "TIMING INFO");
//  text.Render(buffer, .6, -0.925 + spacing * 11, sx, sy);
//  sprintf(buffer, "STEP     %04f", physics_system->GetTimerStep());
//  text.Render(buffer, .6, -0.925 + spacing * 10, sx, sy);
//  sprintf(buffer, "BROAD    %04f", physics_system->GetTimerCollisionBroad());
//  text.Render(buffer, .6, -0.925 + spacing * 9, sx, sy);
//  sprintf(buffer, "NARROW   %04f", physics_system->GetTimerCollisionNarrow());
//  text.Render(buffer, .6, -0.925 + spacing * 8, sx, sy);
//  sprintf(buffer, "SOLVE    %04f", physics_system->GetTimerLcp());
//  text.Render(buffer, .6, -0.925 + spacing * 7, sx, sy);
//  sprintf(buffer, "UPDATE   %04f", physics_system->GetTimerUpdate());
//  text.Render(buffer, .6, -0.925 + spacing * 6, sx, sy);
//
//  if (ChSystemParallelDVI* parallel_sys = dynamic_cast<ChSystemParallelDVI*>(physics_system)) {
//    int3 grid_size = parallel_sys->data_manager->measures.collision.grid_size;
//    real3 bin_size_vec = 1.0 / parallel_sys->data_manager->measures.collision.bin_size_vec;
//    real3 min_pt = parallel_sys->data_manager->measures.collision.min_bounding_point;
//    real3 max_pt = parallel_sys->data_manager->measures.collision.max_bounding_point;
//    real3 center = (min_pt + max_pt) * .5;
//    int max_aabb_per_bin = parallel_sys->data_manager->measures.collision.max_aabb_per_bin;
//    sprintf(buffer, "COLLISION INFO");
//    text.Render(buffer, .6, 0.925 - spacing * 11, sx, sy);
//    sprintf(buffer, "DIMS  [%d,%d,%d]", grid_size.x, grid_size.y, grid_size.z);
//    text.Render(buffer, .6, 0.925 - spacing * 12, sx, sy);
//    sprintf(buffer, "MAX   %d", max_aabb_per_bin);
//    text.Render(buffer, .6, 0.925 - spacing * 13, sx, sy);
//    sprintf(buffer, "SX    %f", bin_size_vec.x);
//    text.Render(buffer, .6, 0.925 - spacing * 14, sx, sy);
//    sprintf(buffer, "SY    %f", bin_size_vec.y);
//    text.Render(buffer, .6, 0.925 - spacing * 15, sx, sy);
//    sprintf(buffer, "SZ    %f", bin_size_vec.z);
//    text.Render(buffer, .6, 0.925 - spacing * 16, sx, sy);
//    sprintf(buffer, "RIGID %d", parallel_sys->data_manager->num_contacts);
//    text.Render(buffer, .6, 0.925 - spacing * 17, sx, sy);
//    //      sprintf(buffer, "BOUND %d", parallel_sys->data_manager->num_boundary_contacts);
//    //      text.Render(buffer, .6, 0.925 - spacing * 18, sx, sy);
//    //      sprintf(buffer, "FLUID %d", parallel_sys->data_manager->num_fluid_contacts);
//    //      text.Render(buffer, .6, 0.925 - spacing * 19, sx, sy);
//  }
//
//  sprintf(buffer, "RENDER INFO");
//  text.Render(buffer, .6, -0.925 + spacing * 4, sx, sy);
//  sprintf(buffer, "GEOMETRY %04f", time_geometry);
//  text.Render(buffer, .6, -0.925 + spacing * 3, sx, sy);
//  sprintf(buffer, "TEXT     %04f", time_text);
//  text.Render(buffer, .6, -0.925 + spacing * 2, sx, sy);
//  sprintf(buffer, "TOTAL    %04f", time_total);
//  text.Render(buffer, .6, -0.925 + spacing * 1, sx, sy);
//  sprintf(buffer, "FPS      %04d", int(fps));
//  text.Render(buffer, .6, -0.925 + spacing * 0, sx, sy);
//
//  if (ChSystemParallelDVI* parallel_sys = dynamic_cast<ChSystemParallelDVI*>(physics_system)) {
//    sprintf(buffer, "TimerA:  %04f", parallel_sys->data_manager->system_timer.GetTime("ChSolverParallel_solverA"));
//    text.Render(buffer, -.95, -0.925 + spacing * 9, sx, sy);
//    sprintf(buffer, "TimerB:  %04f", parallel_sys->data_manager->system_timer.GetTime("ChSolverParallel_solverB"));
//    text.Render(buffer, -.95, -0.925 + spacing * 8, sx, sy);
//    sprintf(buffer, "TimerC:  %04f", parallel_sys->data_manager->system_timer.GetTime("ChSolverParallel_solverC"));
//    text.Render(buffer, -.95, -0.925 + spacing * 7, sx, sy);
//    sprintf(buffer, "TimerD:  %04f", parallel_sys->data_manager->system_timer.GetTime("ChSolverParallel_solverD"));
//    text.Render(buffer, -.95, -0.925 + spacing * 6, sx, sy);
//    sprintf(buffer, "TimerE:  %04f", parallel_sys->data_manager->system_timer.GetTime("ChSolverParallel_solverE"));
//    text.Render(buffer, -.95, -0.925 + spacing * 5, sx, sy);
//    sprintf(buffer, "TimerF:  %04f", parallel_sys->data_manager->system_timer.GetTime("ChSolverParallel_solverF"));
//    text.Render(buffer, -.95, -0.925 + spacing * 4, sx, sy);
//    sprintf(buffer, "TimerG:  %04f", parallel_sys->data_manager->system_timer.GetTime("ChSolverParallel_solverG"));
//    text.Render(buffer, -.95, -0.925 + spacing * 3, sx, sy);
//    sprintf(buffer, "Shur A:  %04f", parallel_sys->data_manager->system_timer.GetTime("ChSolverParallel_shurA"));
//    text.Render(buffer, -.95, -0.925 + spacing * 2, sx, sy);
//    sprintf(buffer, "Shur B:  %04f", parallel_sys->data_manager->system_timer.GetTime("ChSolverParallel_shurB"));
//    text.Render(buffer, -.95, -0.925 + spacing * 1, sx, sy);
//    sprintf(buffer, "Proj  :  %04f", parallel_sys->data_manager->system_timer.GetTime("ChSolverParallel_Project"));
//    text.Render(buffer, -.95, -0.925 + spacing * 0, sx, sy);
//    float posx = -.6;
//    sprintf(buffer, "B_Initial : %04f", parallel_sys->data_manager->system_timer.GetTime("Broadphase_Init"));
//    text.Render(buffer, posx, -0.925 + spacing * 9, sx, sy);
//    sprintf(buffer, "B_AABBBINC: %04f", parallel_sys->data_manager->system_timer.GetTime("Broadphase_AABB_BIN_Count"));
//    text.Render(buffer, posx, -0.925 + spacing * 8, sx, sy);
//    sprintf(buffer, "B_AABBBINS: %04f", parallel_sys->data_manager->system_timer.GetTime("Broadphase_AABB_BIN_Store"));
//    text.Render(buffer, posx, -0.925 + spacing * 7, sx, sy);
//    sprintf(buffer, "B_SORT_RED: %04f", parallel_sys->data_manager->system_timer.GetTime("Broadphase_SortReduce"));
//    text.Render(buffer, posx, -0.925 + spacing * 6, sx, sy);
//    sprintf(buffer, "BAABBAABBC: %04f", parallel_sys->data_manager->system_timer.GetTime("Broadphase_AABB_AABB_Count"));
//    text.Render(buffer, posx, -0.925 + spacing * 5, sx, sy);
//    sprintf(buffer, "BAABBAABBS: %04f", parallel_sys->data_manager->system_timer.GetTime("Broadphase_AABB_AABB_Store"));
//    text.Render(buffer, posx, -0.925 + spacing * 4, sx, sy);
//    sprintf(buffer, "B_POST    : %04f", parallel_sys->data_manager->system_timer.GetTime("Broadphase_Post"));
//    text.Render(buffer, posx, -0.925 + spacing * 3, sx, sy);
//    sprintf(buffer, "BROADPHASE: %04f", parallel_sys->data_manager->system_timer.GetTime("Broadphase"));
//    text.Render(buffer, posx, -0.925 + spacing * 2, sx, sy);
//
//    posx = -.6 + .45;
//    sprintf(buffer, "BuildD : %04f", parallel_sys->data_manager->system_timer.GetTime("BuildD"));
//    text.Render(buffer, posx, -0.925 + spacing * 9, sx, sy);
//    sprintf(buffer, "BuildDA: %04f", parallel_sys->data_manager->system_timer.GetTime("BuildDAllocate"));
//    text.Render(buffer, posx, -0.925 + spacing * 8, sx, sy);
//    sprintf(buffer, "BuildDC: %04f", parallel_sys->data_manager->system_timer.GetTime("BuildDCompute"));
//    text.Render(buffer, posx, -0.925 + spacing * 7, sx, sy);
//    sprintf(buffer, "BuildE : %04f", parallel_sys->data_manager->system_timer.GetTime("BuildE"));
//    text.Render(buffer, posx, -0.925 + spacing * 6, sx, sy);
//    sprintf(buffer, "BuildN : %04f", parallel_sys->data_manager->system_timer.GetTime("BuildN"));
//    text.Render(buffer, posx, -0.925 + spacing * 5, sx, sy);
//    sprintf(buffer, "BuildM : %04f", parallel_sys->data_manager->system_timer.GetTime("BuildM"));
//    text.Render(buffer, posx, -0.925 + spacing * 4, sx, sy);
//    sprintf(buffer, "Buildb : %04f", parallel_sys->data_manager->system_timer.GetTime("Buildb"));
//    text.Render(buffer, posx, -0.925 + spacing * 3, sx, sy);
//    sprintf(buffer, "SchurP : %04f", parallel_sys->data_manager->system_timer.GetTime("ShurProduct"));
//    text.Render(buffer, posx, -0.925 + spacing * 2, sx, sy);
//  }
}