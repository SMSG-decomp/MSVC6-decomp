c2_tuple * __fastcall asm_print_code_line(c2_tuple *t,uint32_t *offset)

{
  uint32_t offset_00;
  int iVar1;
  c2_tuple *t_00;
  int n;
  uint8_t local_40 [64];
  
  if (t->op != 0x162) {
    t_00 = t;
    if ((g_x86_op_flags[t->op] & 0x100) != 0) {
      t_00 = t->next;
    }
    n = 0;
    if (g_listing_on == 0) {
      asm_pad_to_column(8);
    }
    else {
      offset_00 = *offset;
      n = encode_instruction(t,local_40,offset_00,0,(c2_fe_symbol *)0x0);
      if (t_00 != t) {
        iVar1 = encode_instruction(t_00,local_40 + n,offset_00 + n,0,(c2_fe_symbol *)0x0);
        n = n + iVar1;
      }
      if (g_opt_listing_code_bytes != 0) {
        asm_print_code_bytes(offset_00,n,local_40);
        asm_pad_to_column(0x18);
      }
      *offset = offset_00 + n;
    }
    asm_print_instruction(t);
    if (t_00 != t) {
      asm_print_instruction(t_00);
    }
    asm_print_operand_comments(t,n);
    g_asm_column = 0;
    asm_printf(g_asm_newline);
    return t_00;
  }
  return t;
}

