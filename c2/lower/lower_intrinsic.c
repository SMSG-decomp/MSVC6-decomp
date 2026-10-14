c2_tuple * __fastcall lower_intrinsic(c2_tuple *t)

{
  char cVar1;
  ushort uVar2;
  ushort type;
  c2_eh_alloca_marker *pcVar3;
  c2_function *pcVar4;
  c2_tuple *pcVar5;
  c2_tuple *t_00;
  c2_init *pcVar6;
  c2_const_operand *pcVar7;
  c2_operand *pcVar8;
  c2_operand *pcVar9;
  uint32_t uVar10;
  c2_symbol *pcVar11;
  c2_operand *dst;
  c2_fe_symbol *pcVar12;
  c2_operand **ppcVar13;
  uint uVar14;
  uint16_t uVar15;
  char *pcVar16;
  int16_t kind;
  int arena;
  uint8_t uVar17;
  code *pcVar18;
  uint32_t attrs;
  c2_tuple *work;
  c2_tuple *def_tuple;
  c2_operand *local_24;
  c2_operand *local_20;
  c2_operand *local_1c;
  c2_operand *local_18;
  c2_operand *local_14 [5];
  c2_insert_fn *insert_fn;
  
  local_1c = (c2_operand *)0x0;
  if (((((t->u20).intrinsic.id == 0xa5) &&
       (pcVar8 = t->src->next->sym->def->src, (1 << (pcVar8->kind & 0x1f) & 0x18U) != 0)) &&
      (pcVar12 = pcVar8->sym->fe, pcVar12 != (c2_fe_symbol *)0x0)) && (pcVar12->role == '%')) {
    uVar14 = (uint)(pcVar12->u44).length;
    if ((pcVar12->u44).length == 0) {
      pcVar6 = data_def_find_by_id(pcVar12->id);
      uVar14 = 0xffffffff;
      pcVar16 = (char *)(pcVar6->next->u08).header.offset;
      do {
        if (uVar14 == 0) break;
        uVar14 = uVar14 - 1;
        cVar1 = *pcVar16;
        pcVar16 = pcVar16 + 1;
      } while (cVar1 != '\0');
      uVar14 = ~uVar14;
      (pcVar12->u44).length = (uint16_t)uVar14;
    }
    insert_fn = tuple_insert_before;
    (t->u24).intrinsic_flag = 1;
    pcVar5 = t;
    pcVar7 = operand_new_intconst(0x1004,uVar14 & 0xffff,0);
    def_tuple = tuple_new_unary_temp(0x15a,0x1004,pcVar7,insert_fn,pcVar5);
    pcVar8 = t->src;
    (t->u20).intrinsic.id = 0xaa;
    work = (c2_tuple *)def_tuple->dst;
    if (pcVar8->next->next == (c2_operand *)0x0) {
      tuple_append_src(t,(c2_operand *)work);
    }
    else {
      work = (c2_tuple *)node_clone((c2_node *)work);
      ((c2_operand *)work)->flags = ((c2_operand *)work)->flags | 0x10;
      ((c2_operand *)work)->next = pcVar8->next->next;
      pcVar8->next->next = (c2_operand *)work;
    }
  }
  bind_intrinsic_operand_registers(t);
  lower_pending_arg_copies(t);
  pcVar8 = t->src;
  if (pcVar8 != (c2_operand *)0x0) {
    ppcVar13 = local_14;
    pcVar9 = pcVar8;
    do {
      if (pcVar9->kind == '\v') break;
      *ppcVar13 = pcVar9;
      pcVar9 = pcVar9->next;
      ppcVar13 = ppcVar13 + 1;
    } while (pcVar9 != (c2_operand *)0x0);
  }
  uVar2 = (t->u20).intrinsic.id;
  uVar14 = (uint)uVar2;
  if (0xd8 < uVar14) {
    switch(uVar14) {
    case 0xd9:
    case 0xda:
    case 0x17a:
    case 0x17b:
    case 0x17d:
      goto switchD_10764232_caseD_d7;
    case 0xdb:
      if ((g_cur_function->fsym->attrs & 0x1000) == 0) {
        if ((g_cur_function->flags & 0x18000) != 0) {
          work = lower_cxx_longjmp_unwind(local_14[0]->sym->def->prev,&local_20,&local_1c,&local_18)
          ;
          uVar10 = 3;
          goto LAB_10770332;
        }
        pcVar9 = operand_new_intconst(0x1004,0,0);
        pcVar5 = local_14[0]->sym->def;
        pcVar18 = tuple_insert_before;
        work = (c2_tuple *)pcVar9;
      }
      else {
        work = lower_seh_longjmp_unwind(local_14[0]->sym->def->prev,&local_20,&local_1c);
        uVar10 = 2;
LAB_10770332:
        pcVar18 = tuple_insert_after;
        pcVar5 = work;
        pcVar9 = operand_new_intconst(0x1004,uVar10,0);
      }
      pcVar5 = tuple_new_unary_temp(0x15a,0x1004,pcVar9,pcVar18,pcVar5);
      def_tuple = (c2_tuple *)node_clone((c2_node *)pcVar5->dst);
      ((c2_operand *)def_tuple)->next = pcVar8;
      t->src = (c2_operand *)def_tuple;
      lower_tuple(pcVar5);
      pcVar12 = fe_symbol_lookup_name("__setjmp3");
      work = (c2_tuple *)operand_for_symbol_ref(pcVar12);
      if ((g_cur_function->fsym->attrs & 0x1000) == 0) {
        if ((g_cur_function->flags & 0x18000) == 0) goto LAB_107703d2;
        tuple_append_src(t,local_20);
        tuple_append_src(t,local_1c);
      }
      else {
        tuple_append_src(t,local_20);
        local_18 = local_1c;
      }
      tuple_append_src(t,local_18);
LAB_107703d2:
      if ((g_cur_function->fsym->attrs & 0x1000) != 0) {
        seh_lower_pseudo_op(t);
      }
      pcVar5 = build_helper_call((c2_node *)t,0xe,(c2_operand *)work,'\0');
      return pcVar5;
    default:
      goto switchD_10764232_caseD_10;
    case 0xde:
      def_tuple = lower_alloca_size(t);
      work = (c2_tuple *)
             operand_new_intconst
                       (0x1004,((local_14[0]->sym->def->src->u18).lo - 1) + g_default_stack_align &
                               ~(g_default_stack_align - 1U),0);
      pcVar5 = emit_alloca_stack_adjust((c2_operand *)work,tuple_insert_before,def_tuple);
      for (pcVar3 = g_eh_alloca_markers;
          (pcVar3 != (c2_eh_alloca_marker *)0x0 && (pcVar3->addr_def != t)); pcVar3 = pcVar3->next)
      {
      }
      pcVar8 = t->dst;
      pcVar3->addr_def = pcVar5;
      t->dst = (c2_operand *)0x0;
      pcVar8->flags = pcVar8->flags & 0xef;
      pcVar18 = tuple_insert_after;
      work = pcVar5;
      pcVar9 = operand_new_hardreg(5,0x1004);
      work = tuple_new(1,0x1004,pcVar8,pcVar9,pcVar18,pcVar5);
      pcVar9 = t->src;
      pcVar8->sym->def = work;
      if (pcVar9->next != (c2_operand *)0x0) {
        pcVar8 = local_14[1]->sym->def->src;
        if (((1 << (pcVar8->kind & 0x1f) & 6U) != 0) && (pcVar8->sym->def != (c2_tuple *)0x0)) {
          def_tuple = pcVar8->sym->def;
          pcVar8 = def_tuple->src;
          tuple_detach_src((c2_node *)def_tuple,pcVar8);
          tuple_unlink_free(def_tuple);
        }
        pcVar18 = tuple_insert_after;
        pcVar5 = work;
        pcVar9 = operand_new_hardreg(5,0x1004);
        tuple_new(1,0x1004,pcVar8,pcVar9,pcVar18,pcVar5);
      }
      tuple_free_src_defs(t);
      t->op = 0x145;
      return t;
    case 0xdf:
      pcVar5 = find_next_use_of_dst(t,(c2_operand **)&work);
      work = find_next_use_of_dst(pcVar5,(c2_operand **)&def_tuple);
      tuple_replace_src(work,(c2_operand *)def_tuple,t->dst);
      tuple_unlink_free(pcVar5);
      pcVar5 = local_14[0]->sym->def;
      pcVar8 = pcVar5->src;
      uVar14 = 1 << (pcVar8->kind & 0x1f) & 6;
      if ((uVar14 == 0) || (t_00 = pcVar8->sym->def, t_00 == (c2_tuple *)0x0)) {
        if (((uVar14 == 0) ||
            ((pcVar11 = pcVar8->sym, pcVar11->cls != '\x03' || (pcVar11->def != (c2_tuple *)0x0))))
           || ((pcVar11->flags7 & 2) == 0)) goto LAB_107645d8;
        t_00 = find_prev_def_of_operand(pcVar5,pcVar8,&local_18);
        pcVar8 = t_00->src;
        if ((1 << (pcVar8->kind & 0x1f) & 6U) != 0) {
          pcVar5 = pcVar8->sym->def;
          if ((pcVar5 != (c2_tuple *)0x0) && ((pcVar8->u18).reg == pcVar8->sym)) {
            work = pcVar5;
            tuple_unlink_free(t_00);
            t_00 = work;
          }
        }
      }
      if (((1 << (t_00->src->kind & 0x1f) & 6U) == 0) ||
         (pcVar5 = t_00->src->sym->def, pcVar5 == (c2_tuple *)0x0)) {
        tuple_unlink_free(t_00);
      }
      else {
        work = pcVar5;
        tuple_unlink_free(t_00);
        pcVar5 = work;
        pcVar8 = operand_new_hardreg(1,0x1004);
        tuple_replace_dst(pcVar5,pcVar5->dst,pcVar8);
      }
LAB_107645d8:
      work = local_14[1]->sym->def;
      work = (c2_tuple *)
             operand_new_intconst
                       (0x1004,((work->src->u18).lo - 1) + g_default_stack_align &
                               ~(g_default_stack_align - 1U),0);
      tuple_free_src_defs(t);
      node_free((c2_node *)local_14[0]);
      node_free((c2_node *)local_14[1]);
      t->src = (c2_operand *)work;
      return t;
    case 0xe0:
      goto switchD_10764232_caseD_a8;
    case 0xe1:
      goto switchD_10764232_caseD_a9;
    case 0xe5:
    case 0x153:
      if ((g_cur_function->flags & 0x100000) == 0) {
        type = t->type;
        attrs = 0;
        uVar17 = '\x01';
        arena = 1;
        kind = 3;
        uVar10 = type_class_to_symbol_class(type);
        pcVar12 = fe_symbol_new_local_cur((uint16_t)uVar10,type & 0xfff,kind,arena,uVar17,attrs);
        pcVar12->name = "__$ReturnAddr";
        g_return_addr_local = pcVar12;
        pcVar12->offset = 4;
        pcVar11 = fe_symbol_get_storage(pcVar12);
        pcVar11->flags6 = pcVar11->flags6 | 4;
      }
      if (uVar2 == 0xe5) {
        work = (c2_tuple *)operand_for_fe_symbol(g_return_addr_local);
      }
      else {
        work = (c2_tuple *)operand_new_symaddr(0x14a,g_return_addr_local->storage_sym);
      }
      work = tuple_new(1,t->dst->type,t->dst,(c2_operand *)work,tuple_insert_after,t);
      if (((t->dst->kind == '\x01') && (pcVar11 = t->dst->sym, pcVar11->cls == '\x03')) &&
         (pcVar11->def != (c2_tuple *)0x0)) {
        if (pcVar11->storage->part_next == (c2_symbol *)0x0) {
          pcVar11->def = work;
        }
        else {
          symbol_mark_overlapping_parts(pcVar11,work);
        }
      }
      pcVar4 = g_cur_function;
      t->op = 0x145;
      pcVar4->flags = pcVar4->flags | 0x100000;
      return t;
    case 0x11b:
    case 0x11c:
    case 0x11d:
    case 0x13e:
    case 0x13f:
    case 0x14b:
      pcVar18 = tuple_insert_before;
      g_cur_function->flags = g_cur_function->flags | 0x20000;
      pcVar5 = t;
      pcVar7 = operand_new_intconst(0x1004,uVar14,0);
      work = tuple_new_src_only(0x166,t->type,pcVar7,pcVar18,pcVar5);
      work->line = t->line;
      pcVar8 = t->dst;
      if (((pcVar8 != (c2_operand *)0x0) && ((1 << (pcVar8->kind & 0x1f) & 6U) != 0)) &&
         (pcVar8->sym->def != (c2_tuple *)0x0)) {
        def_tuple = (c2_tuple *)pcVar8;
        tuple_detach_dst(t,pcVar8);
        tuple_append_dst(work,(c2_operand *)def_tuple);
        pcVar11 = (def_tuple->u14).expr;
        if (pcVar11->storage->part_next == (c2_symbol *)0x0) {
          pcVar11->def = work;
        }
        else {
          symbol_mark_overlapping_parts(pcVar11,work);
        }
      }
      tuple_detach_src((c2_node *)t,local_14[0]);
      tuple_append_src(work,local_14[0]);
      def_tuple = local_14[0]->sym->def;
      def_tuple->op = 1;
      tuple_remove_dst(def_tuple,def_tuple->dst);
      tuple_remove_src(def_tuple,def_tuple->src->next);
      tuple_append_dst(def_tuple,local_14[0]);
      uVar15 = (t->u20).intrinsic.id;
      if ((uVar15 == 0x11b) || (uVar15 == 0x11c)) {
        pcVar18 = tuple_insert_before;
        uVar10 = (-(uint)(uVar15 != 0x11b) & 0xfffffffe) + 1;
        pcVar5 = work;
        pcVar7 = operand_new_intconst(0x1004,uVar10,(int)uVar10 >> 0x1f);
        def_tuple = tuple_new_unary_temp(1,0x1004,pcVar7,pcVar18,pcVar5);
        pcVar8 = def_tuple->dst;
LAB_10770b20:
        tuple_append_src(work,pcVar8);
      }
      else {
        tuple_detach_src((c2_node *)t,local_14[1]);
        tuple_append_src(work,local_14[1]);
        def_tuple = local_14[1]->sym->def;
        def_tuple->op = 1;
        tuple_remove_dst(def_tuple,def_tuple->dst);
        tuple_remove_src(def_tuple,def_tuple->src->next);
        tuple_append_dst(def_tuple,local_14[1]);
        uVar15 = (t->u20).intrinsic.id;
        if (uVar15 == 0x13f) {
          tuple_detach_src((c2_node *)t,local_14[2]);
          tuple_append_src(work,local_14[2]);
          def_tuple = local_14[2]->sym->def;
          def_tuple->op = 1;
          tuple_remove_dst(def_tuple,def_tuple->dst);
          tuple_remove_src(def_tuple,def_tuple->src->next);
          tuple_append_dst(def_tuple,local_14[2]);
          (local_14[2]->u18).reg = g_reg_symbols + 1;
          (local_14[2]->sym->def->dst->u18).reg = g_reg_symbols + 1;
        }
        else if ((uVar15 == 0x11d) && (g_opt_nolock != 0)) {
          def_tuple = tuple_new_pseudo(0x19e,0x1004);
          tuple_insert_before(work,def_tuple);
          pcVar8 = operand_new_temp(0x1004);
          (pcVar8->u18).reg = g_reg_symbols + 1;
          pcVar8->sym->def = def_tuple;
          tuple_append_dst(def_tuple,pcVar8);
          goto LAB_10770b20;
        }
      }
      if (g_opt_global != 0) {
        uVar10 = tuple_first_memeffect_dst_value(t);
        pcVar8 = operand_new_memeffect(uVar10);
        tuple_append_dst(work,pcVar8);
        uVar10 = tuple_get_memeffect_alias(t);
        pcVar8 = operand_new_memeffect(uVar10);
        tuple_append_src(work,pcVar8);
      }
LAB_10770aae:
      t->op = 0x145;
      return t;
    case 0x177:
      work = tuple_new_nooperands(0x72,t->type,tuple_insert_after,t);
      uVar10 = 0x16b;
      if ((local_14[0]->type & 0xf000) != 0x5000) {
        uVar10 = 0x15b;
      }
      def_tuple = tuple_new(uVar10,local_14[0]->type,t->dst,local_14[0]->sym->def->src,
                            tuple_insert_after,work);
      if (((def_tuple->dst->kind == '\x01') &&
          (pcVar11 = def_tuple->dst->sym, pcVar11->cls == '\x03')) &&
         (pcVar11->def != (c2_tuple *)0x0)) {
        if (pcVar11->storage->part_next == (c2_symbol *)0x0) {
          pcVar11->def = def_tuple;
        }
        else {
          symbol_mark_overlapping_parts(pcVar11,def_tuple);
        }
      }
      if (((1 << (def_tuple->src->kind & 0x1f) & 6U) != 0) &&
         (def_tuple->src->sym->def != (c2_tuple *)0x0)) {
        lower_copy_pseudo(def_tuple);
      }
      tuple_free_src_defs(t);
      t->op = 0x145;
      return t;
    case 0x17e:
      pcVar5 = lower_eh_handler_thunk(t);
      return pcVar5;
    case 0x184:
      pcVar5 = find_next_use_of_dst(t,(c2_operand **)&work);
      work = find_next_use_of_dst(pcVar5,(c2_operand **)&def_tuple);
      pcVar8 = t->dst;
      tuple_replace_src(work,(c2_operand *)def_tuple,pcVar8);
      tuple_replace_dst(t,pcVar8,pcVar5->dst);
      symbol_mark_overlapping_parts(t->dst->sym,t);
      tuple_unlink_free(pcVar5);
      lower_block_copy(t);
      return t;
    case 0x186:
      pcVar12 = g_dlp_profiling_sym;
      if (g_dlp_profiling_sym == (c2_fe_symbol *)0x0) {
        pcVar12 = fe_symbol_lookup_name("__DLP_Profiling@8");
        g_dlp_profiling_sym = pcVar12;
      }
      break;
    case 0x187:
      pcVar12 = g_cap_profiling_sym;
      if (g_cap_profiling_sym == (c2_fe_symbol *)0x0) {
        pcVar12 = fe_symbol_lookup_name("__CAP_Profiling@4");
        g_cap_profiling_sym = pcVar12;
      }
      break;
    case 0x188:
      pcVar12 = g_cap_start_profiling_sym;
      if (g_cap_start_profiling_sym == (c2_fe_symbol *)0x0) {
        pcVar12 = fe_symbol_lookup_name("__CAP_Start_Profiling@8");
        g_cap_start_profiling_sym = pcVar12;
      }
      break;
    case 0x189:
      pcVar12 = g_cap_end_profiling_sym;
      if (g_cap_end_profiling_sym == (c2_fe_symbol *)0x0) {
        pcVar12 = fe_symbol_lookup_name("__CAP_End_Profiling@4");
        g_cap_end_profiling_sym = pcVar12;
      }
    }
    uVar17 = '\x10';
    pcVar8 = operand_for_symbol_ref(pcVar12);
    pcVar5 = tuple_make_helper_call_2(t,0xe,pcVar8,uVar17);
    return pcVar5;
  }
  if (uVar14 == 0xd8) {
    pcVar5 = lower_alloca_intrinsic(t);
    return pcVar5;
  }
  switch(uVar14) {
  case 0xd:
    uVar15 = 0x1001;
    break;
  case 0xe:
    uVar15 = 0x1002;
    break;
  case 0xf:
    uVar15 = 0x1004;
    break;
  default:
switchD_10764232_caseD_10:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\cgintrin.c",0x265);
  case 0x97:
    local_1c = (c2_operand *)0x1;
  case 0x96:
    lower_memcpy_memset(t,local_14,(int)(short)(t->u20).intrinsic.arg,(int)local_1c);
    t->op = 0x145;
    return t;
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xa2:
    uVar10 = intrinsic_machine_opcode(uVar14);
    work = tuple_new_binary(uVar10,t->type,t->dst,local_14[0]->sym->def->src,
                            local_14[1]->sym->def->src,tuple_insert_after,t);
    pcVar11 = t->dst->sym;
    goto LAB_10770249;
  case 0xa3:
    lower_strcpy_or_strset(t,local_14,1);
    t->op = 0x145;
    return t;
  case 0xa4:
    lower_strcpy_or_strset(t,local_14,0);
    t->op = 0x145;
    return t;
  case 0xa5:
    lower_strcmp_inline(t,local_14);
    t->op = 0x145;
    return t;
  case 0xa6:
    lower_strcat(t,local_14);
    t->op = 0x145;
    return t;
  case 0xa7:
    work = (c2_tuple *)emit_repne_scasb_strlen(t,local_14[0],&local_24,0,0x1004);
    local_24 = (c2_operand *)tuple_new(1,t->type,t->dst,(c2_operand *)work,tuple_insert_before,t);
    if (((1 << (t->dst->kind & 0x1f) & 6U) != 0) &&
       (pcVar11 = t->dst->sym, pcVar11->def != (c2_tuple *)0x0)) {
      if (pcVar11->storage->part_next != (c2_symbol *)0x0) {
        symbol_mark_overlapping_parts(pcVar11,(c2_tuple *)local_24);
        t->op = 0x145;
        return t;
      }
      pcVar11->def = (c2_tuple *)local_24;
      t->op = 0x145;
      return t;
    }
    goto LAB_10770aae;
  case 0xa8:
  case 0xaf:
switchD_10764232_caseD_a8:
    uVar10 = intrinsic_machine_opcode(uVar14);
    pcVar8 = t->dst;
    if (pcVar8 == (c2_operand *)0x0) {
      uVar2 = t->type;
      pcVar18 = tuple_insert_after;
      pcVar5 = t;
      pcVar8 = operand_retype(local_14[0]->sym->def->src,0x1002,0);
      pcVar11 = reg_find_subreg(g_reg_symbols + 1,(uVar2 & 0xfff) << 3,0);
      pcVar9 = operand_new_hardreg(pcVar11->id,uVar2);
      tuple_new(uVar10,uVar2,pcVar9,pcVar8,pcVar18,pcVar5);
      tuple_free_src_defs(t);
      t->op = 0x145;
      return t;
    }
    pcVar18 = tuple_insert_after;
    pcVar5 = t;
    pcVar9 = operand_retype(local_14[0]->sym->def->src,0x1002,0);
    work = tuple_new(uVar10,t->type,pcVar8,pcVar9,pcVar18,pcVar5);
    pcVar11 = t->dst->sym;
    if (pcVar11->storage->part_next != (c2_symbol *)0x0) {
      symbol_mark_overlapping_parts(pcVar11,work);
      tuple_free_src_defs(t);
      t->op = 0x145;
      return t;
    }
    pcVar11->def = work;
    tuple_free_src_defs(t);
    t->op = 0x145;
    return t;
  case 0xa9:
  case 0xb0:
switchD_10764232_caseD_a9:
    uVar10 = intrinsic_machine_opcode(uVar14);
    insert_fn = tuple_insert_after;
    pcVar5 = t;
    pcVar8 = operand_retype(local_14[1]->sym->def->src,local_14[1]->type,0);
    pcVar9 = operand_retype(local_14[0]->sym->def->src,0x1002,0);
    work = tuple_new_binary(uVar10,local_14[1]->type,local_14[0]->sym->def->dst,pcVar9,pcVar8,
                            insert_fn,pcVar5);
    node_free((c2_node *)work->dst);
    pcVar8 = t->dst;
    work->dst = (c2_operand *)0x0;
    if (pcVar8 == (c2_operand *)0x0) goto LAB_10770275;
    pcVar9 = work->src->next;
    if (((1 << (pcVar9->kind & 0x1f) & 6U) != 0) && (pcVar9->sym->def != (c2_tuple *)0x0)) {
      def_tuple = (c2_tuple *)operand_new_temp(pcVar9->type);
      ((c2_operand *)def_tuple)->sym->def = work;
      work->dst = (c2_operand *)def_tuple;
      ((c2_operand *)def_tuple)->flags = ((c2_operand *)def_tuple)->flags | 0x10;
      pcVar11 = reg_find_subreg(g_reg_symbols + 1,(((c2_operand *)def_tuple)->type & 0xfff) << 3,0);
      def_tuple->src = (c2_operand *)pcVar11;
      pcVar9 = (c2_operand *)def_tuple;
    }
    def_tuple = (c2_tuple *)pcVar9;
    uVar15 = pcVar8->type;
    if (((def_tuple->type ^ uVar15) & 0xfff) != 0) {
      insert_fn = tuple_insert_after;
      pcVar9 = (c2_operand *)def_tuple;
      pcVar5 = work;
      dst = operand_new_temp(uVar15);
      work = tuple_new(0x15f,uVar15,dst,pcVar9,insert_fn,pcVar5);
      def_tuple = (c2_tuple *)work->dst;
      ((c2_operand *)def_tuple)->sym->def = work;
    }
    work = tuple_new(1,pcVar8->type,pcVar8,(c2_operand *)def_tuple,tuple_insert_after,work);
    pcVar11 = pcVar8->sym;
LAB_10770249:
    if (pcVar11->storage->part_next == (c2_symbol *)0x0) {
      pcVar11->def = work;
      tuple_free_src_defs(t);
      t->op = 0x145;
      return t;
    }
    symbol_mark_overlapping_parts(pcVar11,work);
LAB_10770275:
    tuple_free_src_defs(t);
    t->op = 0x145;
    return t;
  case 0xaa:
    lower_memcmp(t);
    t->op = 0x145;
    return t;
  case 0xac:
    lower_memcpy_memset(t,local_14,1,0);
    t->op = 0x145;
    return t;
  case 0xad:
    lower_memcpy_memset(t,local_14,1,1);
    t->op = 0x145;
    return t;
  case 0xb1:
  case 0xb2:
    insert_fn = tuple_insert_after;
    pcVar5 = t;
    pcVar8 = operand_new_hardreg(0x42,0x8000);
    pcVar9 = operand_new_hardreg(0x42,0x8000);
    work = tuple_new((-(uint)(uVar2 != 0xb1) & 0xffffffea) + 0xb2,0x8000,pcVar9,pcVar8,insert_fn,
                     pcVar5);
    tuple_remove_src(work,work->src);
    tuple_free_src_defs(t);
    t->op = 0x145;
    return t;
  case 0xd7:
switchD_10764232_caseD_d7:
    pcVar5 = seh_lower_pseudo_op(t);
    return pcVar5;
  }
  pcVar5 = t->prev;
  def_tuple = (c2_tuple *)pcVar5->src;
  work = (c2_tuple *)operand_new_temp(uVar15);
  local_24 = (c2_operand *)
             emit_sign_extend_high(uVar15,pcVar5,(c2_operand *)work,(c2_operand **)&def_tuple);
  pcVar5 = tuple_new_binary_temp
                     (0x34,uVar15,(c2_operand *)def_tuple,(c2_operand *)work,tuple_insert_after,
                      (c2_tuple *)local_24);
  work = (c2_tuple *)bind_value_to_new_temp(pcVar5,(work->u14).expr,1);
  pcVar8 = t->dst;
  pcVar5 = tuple_new_binary(0x32,uVar15,pcVar8,pcVar5->dst,(c2_operand *)work,tuple_insert_after,
                            pcVar5);
  if (((1 << (pcVar8->kind & 0x1f) & 6U) != 0) &&
     (pcVar11 = pcVar8->sym, pcVar11->def != (c2_tuple *)0x0)) {
    if (pcVar11->storage->part_next == (c2_symbol *)0x0) {
      pcVar11->def = pcVar5;
    }
    else {
      symbol_mark_overlapping_parts(pcVar11,pcVar5);
    }
  }
  (pcVar8->u18).reg = g_reg_symbols + 1;
  tuple_free_src_defs(t);
  t->op = 0x145;
  return (c2_tuple *)local_24;
}

