uint32_t __fastcall sched_should_run(c2_function *fn,int fp_mode)

{
  if ((fp_mode != 0) &&
     ((((g_opt_favor_speed == 0 || ((fn->flags & 8) == 0)) || (g_opt_cpu_target == 4)) ||
      (((g_opt_cpu_target == 6 || (g_opt_vb_float_checks != 0)) || ((fn->flags & 1) != 0)))))) {
    return 0;
  }
  return 1;
}

