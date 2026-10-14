void __thiscall conv_check_nonlvalue_to_reference(c1_conversion *conv,c1_type *type,char is_target)

{
  c1_type *type_00;
  c1_symbol *ctor;
  c1_symbol *sym;
  c1_type *pcVar1;
  c1_conversion *conv_00;
  c1xx_obj_104cb248 local_10 [4];
  
  if (g_ms_extensions == '\0') {
    ctor = (c1_symbol *)
           class_find_member_function_matching(type,(int)g_name_ctor,sym_is_copy_constructor);
    if ((ctor != (c1_symbol *)0x0) && (ctor != (conv->via).function)) {
      diag_elided_copy_constructor_note_init(local_10,conv->source,conv->target,ctor);
      tmpl_pending_push(local_10);
      sym = class_lookup_member_set(g_current_scope,(type->extra).cls,g_name_ctor,2,0);
      expr_set_overload_target_and_check_access(sym,(int)ctor);
      conv_00 = (c1_conversion *)g_arenas[5].cur;
      type_00 = ((ctor->type->extra).params)->list->types[0];
      if (type_00 != (c1_type *)0x0) {
        if (is_target == '\0') {
          g_arenas[5].cur = g_arenas[5].cur + 0x50;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (conv_00 == (c1_conversion *)0x0) {
            conv_00 = (c1_conversion *)0x0;
          }
          else {
            conv_00->op = '`';
            *(c1_u8 *)((int)conv_00 + 1) = '\x02';
            *(c1_u8 *)((int)conv_00 + 2) = '\0';
            *(c1_u8 *)((int)conv_00 + 4) = '\0';
            *(c1_u8 *)((int)conv_00 + 5) = '\0';
            *(c1_u8 *)((int)conv_00 + 6) = '\0';
            *(c1_u8 *)((int)conv_00 + 7) = '\0';
            *(c1_type **)((int)conv_00 + 8) = type;
            *(c1_type **)((int)conv_00 + 0xc) = type_00;
            conv_compute_conversion(conv_00);
          }
          if ((conv_00->flags4e & 1) == 0) {
            conv_report_cannot_convert(conv_00,'\x01');
          }
        }
        else {
          pcVar1 = type_base(type_00);
          if ((pcVar1->code & 0x8f) == 0x83) {
            pcVar1 = type_skip_arrays(pcVar1->base);
          }
          if ((pcVar1->flags & 0x3e0) != 0x20) {
            diag_error(0x268,(uint)conv->op,type,type_00);
            tmpl_pending_pop();
            return;
          }
        }
      }
      tmpl_pending_pop();
    }
  }
  return;
}

