c2_tuple * __fastcall cxx_eh_emit_prolog(c2_tuple *anchor,int emit_registration)

{
  c2_const_operand *pcVar1;
  c2_fe_symbol *pcVar2;
  c2_operand *pcVar3;
  c2_operand *dst;
  c2_operand *pcVar4;
  c2_symbol *pcVar5;
  c2_operand *pcVar6;
  c2_tuple *pcVar7;
  uint8_t call_conv;
  code *pcVar8;
  c2_insert_fn *insert_fn;
  
  g_cxx_eh_prolog_emitted = 1;
  if (emit_registration == 0) {
    if ((g_cur_function->flags & 0x10000) != 0) {
      insert_fn = tuple_insert_after;
      pcVar4 = operand_new_hardreg(5,0x1004);
      pcVar5 = symbol_get_part(g_cxx_eh_record,0x1004,0,g_cxx_eh_next_offset + -4);
      pcVar6 = operand_new_sym(0x14a,0x1004,pcVar5);
      pcVar7 = tuple_new(1,0x1004,pcVar6,pcVar4,insert_fn,anchor);
      return pcVar7;
    }
  }
  else {
    if (g_opt_favor_speed == 0) {
      pcVar2 = get_ehhandler_symbol();
      pcVar4 = operand_new_codeaddr(0x153,pcVar2);
      pcVar8 = tuple_insert_after;
      pcVar6 = operand_new_hardreg(1,0x1004);
      pcVar7 = tuple_new(1,0x1004,pcVar6,pcVar4,pcVar8,anchor);
      pcVar8 = tuple_insert_after;
      call_conv = '\x04';
      pcVar2 = fe_symbol_lookup_name("__EH_prolog");
      pcVar4 = operand_new_codeaddr(0x153,pcVar2);
      pcVar6 = operand_new_hardreg(1,0x1004);
      anchor = tuple_new_call(0xe,0x1004,pcVar6,pcVar4,call_conv,pcVar8,pcVar7);
      pcVar4 = operand_new_hardreg(1,0x1004);
      tuple_append_src(anchor,pcVar4);
      pcVar4 = operand_new_hardreg(5,0x1004);
      tuple_append_src(anchor,pcVar4);
      pcVar4 = operand_new_hardreg(5,0x1004);
      tuple_append_dst(anchor,pcVar4);
      pcVar4 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(anchor,pcVar4);
      g_eh_prolog_call_tuple = anchor;
    }
    else {
      insert_fn = tuple_insert_after;
      pcVar4 = operand_new_hardreg(5,0x1004);
      pcVar1 = operand_new_intconst(0x1004,0xffffffff,-1);
      pcVar6 = operand_new_hardreg(5,0x1004);
      pcVar7 = tuple_new_binary(0xd,0x1004,pcVar6,pcVar1,pcVar4,insert_fn,anchor);
      pcVar2 = get_ehhandler_symbol();
      pcVar4 = operand_new_codeaddr(0x153,pcVar2);
      insert_fn = tuple_insert_after;
      pcVar6 = operand_new_hardreg(5,0x1004);
      pcVar3 = operand_new_hardreg(5,0x1004);
      pcVar7 = tuple_new_binary(0xd,0x1004,pcVar3,pcVar4,pcVar6,insert_fn,pcVar7);
      pcVar2 = extern_symbol_lookup_or_create((uint8_t *)"__except_list");
      pcVar5 = fe_symbol_get_storage(pcVar2);
      pcVar6 = operand_new_sym(0x14b,0x1004,pcVar5);
      insert_fn = tuple_insert_after;
      pcVar6->flags11 = pcVar6->flags11 & 0xfd | 5;
      pcVar4 = pcVar6;
      pcVar3 = operand_new_hardreg(1,0x1004);
      pcVar7 = tuple_new(1,0x1004,pcVar3,pcVar4,insert_fn,pcVar7);
      pcVar8 = tuple_insert_after;
      pcVar4 = operand_new_hardreg(5,0x1004);
      pcVar3 = operand_new_hardreg(1,0x1004);
      dst = operand_new_hardreg(5,0x1004);
      pcVar7 = tuple_new_binary(0xd,0x1004,dst,pcVar3,pcVar4,pcVar8,pcVar7);
      pcVar8 = tuple_insert_after;
      pcVar4 = operand_new_hardreg(5,0x1004);
      anchor = tuple_new(1,0x1004,pcVar6,pcVar4,pcVar8,pcVar7);
    }
    if (g_cxx_eh_next_offset != 0) {
      pcVar8 = tuple_insert_after;
      pcVar1 = operand_new_intconst(0x1004,4,0);
      pcVar4 = operand_new_hardreg(5,0x1004);
      pcVar6 = operand_new_hardreg(5,0x1004);
      anchor = tuple_new_binary(0x32,0x1004,pcVar6,pcVar4,pcVar1,pcVar8,anchor);
      pcVar4 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(anchor,pcVar4);
    }
  }
  return anchor;
}

