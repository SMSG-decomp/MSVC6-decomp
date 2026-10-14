c2_tuple * __fastcall seh_emit_prolog(c2_tuple *anchor,int emit_registration)

{
  uint8_t *puVar1;
  c2_operand *pcVar2;
  c2_symbol *sym;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_const_operand *pcVar5;
  c2_operand *pcVar6;
  c2_fe_symbol *pcVar7;
  c2_operand *dst;
  char *name;
  code *pcVar8;
  c2_insert_fn *insert_fn;
  
  if (emit_registration == 0) {
    if ((g_cur_function->flags & 0x2000) != 0) {
      insert_fn = tuple_insert_after;
      pcVar2 = operand_new_hardreg(5,0x1004);
      sym = symbol_get_part(g_seh_record,0x1004,0,-(uint)(g_opt_basic != 0) & 8);
      pcVar3 = operand_new_sym(0x14a,0x1004,sym);
      pcVar4 = tuple_new(1,0x1004,pcVar3,pcVar2,insert_fn,anchor);
      puVar1 = &pcVar4->dst->flags11;
      *puVar1 = *puVar1 | 8;
      return pcVar4;
    }
  }
  else {
    insert_fn = tuple_insert_after;
    if (g_opt_basic == 0) {
      pcVar2 = operand_new_hardreg(5,0x1004);
      pcVar5 = operand_new_intconst(0x1004,0xffffffff,-1);
      pcVar3 = operand_new_hardreg(5,0x1004);
      pcVar4 = tuple_new_binary(0xd,0x1004,pcVar3,pcVar5,pcVar2,insert_fn,anchor);
      pcVar2 = operand_for_symbol_ref(g_seh_scopetable);
      insert_fn = tuple_insert_after;
      pcVar3 = operand_new_hardreg(5,0x1004);
      pcVar6 = operand_new_hardreg(5,0x1004);
      pcVar4 = tuple_new_binary(0xd,0x1004,pcVar6,pcVar2,pcVar3,insert_fn,pcVar4);
      name = "__except_handler3";
    }
    else {
      pcVar5 = operand_new_intconst
                         (0x1004,g_vb_seh_prefix_size + 4U,(int)(g_vb_seh_prefix_size + 4U) >> 0x1f)
      ;
      pcVar2 = operand_new_hardreg(5,0x1004);
      pcVar3 = operand_new_hardreg(5,0x1004);
      pcVar4 = tuple_new_binary(0x32,0x1004,pcVar3,pcVar2,pcVar5,insert_fn,anchor);
      pcVar2 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(pcVar4,pcVar2);
      name = "___vbaExceptHandler";
    }
    pcVar7 = fe_symbol_lookup_name(name);
    pcVar2 = operand_for_symbol_ref(pcVar7);
    insert_fn = tuple_insert_after;
    pcVar3 = operand_new_hardreg(5,0x1004);
    pcVar6 = operand_new_hardreg(5,0x1004);
    pcVar4 = tuple_new_binary(0xd,0x1004,pcVar6,pcVar2,pcVar3,insert_fn,pcVar4);
    pcVar7 = extern_symbol_lookup_or_create((uint8_t *)"__except_list");
    pcVar3 = operand_for_fe_symbol(pcVar7);
    pcVar8 = tuple_insert_after;
    pcVar3->flags11 = pcVar3->flags11 & 0xfd | 5;
    pcVar2 = pcVar3;
    pcVar6 = operand_new_hardreg(1,0x1004);
    pcVar4 = tuple_new(1,0x1004,pcVar6,pcVar2,pcVar8,pcVar4);
    pcVar8 = tuple_insert_after;
    pcVar2 = operand_new_hardreg(5,0x1004);
    pcVar6 = operand_new_hardreg(1,0x1004);
    dst = operand_new_hardreg(5,0x1004);
    pcVar4 = tuple_new_binary(0xd,0x1004,dst,pcVar6,pcVar2,pcVar8,pcVar4);
    pcVar8 = tuple_insert_after;
    pcVar2 = operand_new_hardreg(5,0x1004);
    anchor = tuple_new(1,0x1004,pcVar3,pcVar2,pcVar8,pcVar4);
    if (g_opt_basic == 0) {
      pcVar8 = tuple_insert_after;
      pcVar5 = operand_new_intconst(0x1004,8,0);
      pcVar2 = operand_new_hardreg(5,0x1004);
      pcVar3 = operand_new_hardreg(5,0x1004);
      anchor = tuple_new_binary(0x32,0x1004,pcVar3,pcVar2,pcVar5,pcVar8,anchor);
      pcVar2 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(anchor,pcVar2);
    }
  }
  return anchor;
}

