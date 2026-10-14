c2_fe_symbol * __fastcall materialize_float_constant(c2_operand *opnd)

{
  uint32_t uVar1;
  uint32_t uVar2;
  c2_float_const_pool_entry *pcVar3;
  c2_fe_symbol *pcVar4;
  c2_float_const_pool_entry *pcVar5;
  char *_Dest;
  c2_init *def_rec;
  c2_init *value_rec;
  int iVar6;
  uint size;
  bool bVar7;
  c2_float_const *float_value;
  uint32_t exp_dword;
  
  float_value = (c2_float_const *)opnd->sym;
  size = opnd->type & 0xfff;
  pcVar4 = find_float_constant_pool_entry(float_value,size);
  if (pcVar4 == (c2_fe_symbol *)0x0) {
    pcVar5 = arena_alloc((uint)(g_opt_incremental != 0),0x10);
    pcVar3 = pcVar5;
    pcVar5->next = g_float_const_pool;
    g_float_const_pool = pcVar3;
    iVar6 = g_opt_incremental;
    pcVar5->value = float_value;
    pcVar5->size = size;
    pcVar4 = fe_symbol_new_local_cur(5,size,4,(uint)(iVar6 != 0),(-(iVar6 != 0) & 3U) + 1,0x80);
    bVar7 = g_opt_incremental == 0;
    pcVar5->sym = pcVar4;
    if (bVar7) {
      _Dest = arena_alloc(0,0x1e);
      sprintf(_Dest,"__real@%.1x@%.4hx%.8x%.8x",size,(int)(short)float_value->exp_sign,
              float_value->mantissa_high,float_value->mantissa_low);
      pcVar4->section_id = 0;
      pcVar4->name = _Dest;
      pcVar4->attrs = 0x1a0;
      fe_symbol_choose_section(pcVar4);
    }
    def_rec = alloc_init_record(0);
    pcVar4 = pcVar5->sym;
    uVar1 = pcVar4->id;
    (def_rec->u08).header.offset = 0;
    (def_rec->u08).header.sym_id = uVar1;
    value_rec = alloc_init_record(1);
    (value_rec->u18).repeat = 1;
    def_rec->next = value_rec;
    (value_rec->u08).data.value_kind = 5;
    if (size == 4) {
      (value_rec->u08).data.size = 4;
      iVar6 = fpu_store_float(float_value,(float *)&(value_rec->u08).header.offset);
    }
    else {
      if (size != 8) {
        if (size == 10) {
          uVar1 = float_value->mantissa_low;
          uVar2 = float_value->mantissa_high;
          (value_rec->u08).data.size = 10;
          (value_rec->u08).header.offset = uVar1;
          exp_dword = *(uint32_t *)&float_value->exp_sign;
          (value_rec->u08).header.sym_id = uVar2;
          (value_rec->u08).header.placed = exp_dword;
          init_record_insert_sorted(def_rec);
          return pcVar4;
        }
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\misc.c",0x412);
      }
      (value_rec->u08).data.size = 8;
      iVar6 = fpu_store_double(float_value,(double *)((int)&value_rec->u08 + 4));
    }
    if (iVar6 != 0) {
      warning(2,0x2f4);
    }
    init_record_insert_sorted(def_rec);
  }
  return pcVar4;
}

