void __fastcall encode_reloc_operand(c2_operand *opnd,int nbytes)

{
  c2_fe_symbol *target;
  int fixup_delta;
  
  target = (c2_fe_symbol *)opnd->sym;
  fixup_delta = (int)g_encode_cursor - (int)g_encode_buffer;
  if (g_encode_emit_relocs == 0) {
    if (nbytes == 6) {
LAB_1076c71b:
      emit_value_bytes(0,2);
      emit_value_bytes(0,4);
      return;
    }
  }
  else {
    if (nbytes == 6) {
      (*g_writer_reloc_type9_hook)(fixup_delta,target);
      (*g_hook_add_reloc_dir32)(fixup_delta + 2,target);
      goto LAB_1076c71b;
    }
    (*g_hook_add_reloc_rel32)(fixup_delta,target);
  }
  emit_value_bytes(0,nbytes);
  return;
}

