void __fastcall compute_frame_size(c2_function *fn)

{
  fn->fsym->frame_size =
       (g_default_stack_align - g_frame_cursor) - 1U & ~(g_default_stack_align - 1U);
  return;
}

