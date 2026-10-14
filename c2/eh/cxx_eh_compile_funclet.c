int __fastcall cxx_eh_compile_funclet(void *obj)

{
  c2_function *fn;
  
  fn = *(c2_function **)(*(int *)(*(int *)((int)obj + 0x20) + 4) + 0x34);
  if ((fn->flags & 0x4000) == 0) {
    fn->flags = fn->flags | 0x4000;
    g_current_line_abs = 0;
    g_cur_line = 0;
    pass_select_address_modes(fn);
    pass_lower_function(fn);
    g_no_global_candidates = 1;
    local_color_registers(fn);
    jump_optimize(fn);
    final_lowering_peepholes(fn);
    return 1;
  }
  return 0;
}

