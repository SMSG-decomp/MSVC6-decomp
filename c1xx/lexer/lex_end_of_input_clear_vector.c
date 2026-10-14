int __cdecl
lex_end_of_input_clear_vector
          (c1_vector *vec,c1xx_il_emitter *saved_il_emitter,int saved_opt_Binl,char saved_c8_bit7,
          int saved_token_position)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  vec->count = 0;
  uVar3 = (uint)PTR_104d143c->capacity;
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
    PTR_104d143c->data[uVar3] = (void *)0x0;
  }
  g_pending_destructor_helpers = 0;
  cVar1 = tu_has_pending_special_members();
  if (cVar1 == '\0') {
    cVar1 = tmpl_queue_used_member_bodies();
    if (cVar1 == '\0') {
      g_il_emitter = saved_il_emitter;
      g_opt_Binl = saved_opt_Binl;
      if (saved_c8_bit7 == '\0') {
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffff7f;
      }
      g_token_position = saved_token_position;
      return 0;
    }
  }
  else {
    class_build_vector_helper_tokens();
    class_define_pending_special_members();
  }
  iVar2 = lex_end_of_input();
  g_il_emitter = saved_il_emitter;
  g_opt_Binl = saved_opt_Binl;
  if (saved_c8_bit7 == '\0') {
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffff7f;
  }
  g_token_position = saved_token_position;
  return iVar2;
}

