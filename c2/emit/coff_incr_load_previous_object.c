int coff_incr_load_previous_object(void)

{
  char cVar1;
  char cVar2;
  uint16_t uVar3;
  uint32_t uVar4;
  int *piVar5;
  byte bVar6;
  uint uVar7;
  uint32_t uVar8;
  uint16_t *puVar9;
  uint16_t uVar10;
  size_t sVar11;
  uint32_t size_or_value;
  int iVar12;
  uint _Count;
  uint32_t *_DstBuf;
  c2_coff_section *section_desc;
  uint32_t uVar13;
  char *pcVar14;
  c2_coff_section_out *pcVar15;
  c2_coff_order_cell *pcVar16;
  uint32_t reloc_offset;
  char *pcVar17;
  c2_coff_file_payload *file_payload;
  int iVar18;
  void *_DstBuf_00;
  size_t sVar19;
  c2_coff_section *desc;
  c2_coff_slot *slot;
  uint32_t *name_words;
  short sVar20;
  uint uVar21;
  uint uVar22;
  uint32_t *puVar23;
  uint uVar24;
  char *pcVar25;
  int iVar26;
  c2_coff_slot **slot_cursor;
  uint uStack_58;
  size_t local_54;
  c2_coff_order_cell *order_cursor;
  uint32_t uStack_34;
  char name_buf [9];
  c2_coff_file_header file_header;
  uint16_t sym_type;
  uint32_t line_offset;
  c2_coff_order *order;
  
  name_buf[8] = '\0';
  sVar11 = fread(&file_header,1,0x14,g_coff_object_file);
  uVar3 = file_header.nsections;
  if (sVar11 != 0x14) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x11f4);
  }
  uVar7 = (uint)file_header.nsections;
  size_or_value = prevobj_read_dword();
  if (CONCAT22(file_header.timestamp._2_2_,(undefined2)file_header.timestamp) != size_or_value) {
    g_coff_incremental_update = 0;
    g_coff_section_numbers_final = 1;
    iVar12 = fseek(g_coff_object_file,0,0);
    if (iVar12 != 0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1201);
    }
    iVar12 = _chsize(g_coff_object_file->_file,0);
    if (iVar12 != 0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1202);
    }
    return 0;
  }
  uVar24 = uVar7 * 0x28;
  _Count = file_header.nsymbols * 0x12;
  local_54 = _Count;
  if (_Count < uVar24) {
    local_54 = uVar24;
  }
  _DstBuf = malloc(local_54);
  if (_DstBuf == (uint32_t *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1217);
  }
  g_coff_data_end = prevobj_read_dword();
  g_coff_incr_section_map = (*g_coff_alloc_fn)(uVar7 * 2 + 2);
  sVar11 = fread(_DstBuf,1,uVar24,g_coff_object_file);
  if (sVar11 != uVar24) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1227);
  }
  uStack_58 = 0;
  if (uVar3 != 0) {
    puVar23 = _DstBuf + 4;
    do {
      name_buf._0_4_ = puVar23[-4];
      name_buf._4_4_ = puVar23[-3];
      size_or_value = *puVar23;
      uVar24 = puVar23[1];
      if ((uStack_58 == 0) || ((uVar24 != 0 && (uVar24 < g_coff_incr_data_start)))) {
        g_coff_incr_data_start = uVar24;
      }
      reloc_offset = puVar23[2];
      uVar4 = puVar23[5];
      line_offset = puVar23[3];
      uVar3 = *(uint16_t *)((int)puVar23 + 0x12);
      uVar8 = puVar23[4];
      if (puVar23[-2] != 0) {
        section_desc = (*g_coff_alloc_fn)(0x20);
        uVar13 = coff_list_append(g_coff_sections,section_desc);
        uVar10 = (uint16_t)uVar13;
        section_desc->number = uVar10;
        section_desc->characteristics = uVar4;
        section_desc->signature = 0;
        section_desc->fn_signature = 0;
        if (name_buf[0] == '/') {
          pcVar14 = (char *)atoi(name_buf + 1);
          *(byte *)&section_desc->flags = (byte)section_desc->flags | 0x20;
          section_desc->name = pcVar14;
        }
        else {
          uVar21 = 0xffffffff;
          pcVar14 = name_buf;
          do {
            if (uVar21 == 0) break;
            uVar21 = uVar21 - 1;
            cVar1 = *pcVar14;
            pcVar14 = pcVar14 + 1;
          } while (cVar1 != '\0');
          pcVar17 = (*g_coff_alloc_fn)(~uVar21);
          uVar21 = 0xffffffff;
          pcVar14 = name_buf;
          do {
            pcVar25 = pcVar14;
            if (uVar21 == 0) break;
            uVar21 = uVar21 - 1;
            pcVar25 = pcVar14 + 1;
            cVar1 = *pcVar14;
            pcVar14 = pcVar25;
          } while (cVar1 != '\0');
          uVar21 = ~uVar21;
          pcVar14 = pcVar25 + -uVar21;
          pcVar25 = pcVar17;
          for (uVar22 = uVar21 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {
            *(undefined4 *)pcVar25 = *(undefined4 *)pcVar14;
            pcVar14 = pcVar14 + 4;
            pcVar25 = pcVar25 + 4;
          }
          for (uVar21 = uVar21 & 3; uVar21 != 0; uVar21 = uVar21 - 1) {
            *pcVar25 = *pcVar14;
            pcVar14 = pcVar14 + 1;
            pcVar25 = pcVar25 + 1;
          }
          section_desc->name = pcVar17;
        }
        puVar9 = g_coff_incr_section_map;
        *(byte *)&section_desc->flags = (byte)section_desc->flags | 0x10;
        puVar9[uStack_58 + 1] = uVar10;
        pcVar15 = (*g_coff_alloc_fn)(0x3c);
        section_desc->active = pcVar15;
        pcVar15->size_of_raw_data = size_or_value;
        pcVar15->data_offset = uVar24;
        pcVar15->reloc_offset = reloc_offset;
        pcVar15->line_offset = line_offset;
        pcVar15->fn_section_mark = 1;
        pcVar15->nrelocs = (uint)(ushort)uVar8;
        pcVar15->nlines = uVar3;
        pcVar15->desc = section_desc;
        pcVar15->next = pcVar15;
        pcVar15->header_number = uVar10;
        pcVar16 = (*g_coff_alloc_fn)(8);
        order = g_coff_section_order;
        pcVar16->sec = pcVar15;
        if (order->tail == (c2_coff_order_cell *)0x0) {
          order->head = pcVar16;
        }
        else {
          order->tail->next = pcVar16;
        }
        order->tail = pcVar16;
        order->count = order->count + 1;
        order->inserted = order->inserted + 1;
      }
      uStack_58 = uStack_58 + 1;
      puVar23 = puVar23 + 10;
    } while (uStack_58 < uVar7);
  }
  while( true ) {
    size_or_value = prevobj_read_dword();
    reloc_offset = prevobj_read_dword();
    if ((size_or_value == 0) && (reloc_offset == 0)) break;
    coff_free_range_add(size_or_value,reloc_offset);
    if (size_or_value < g_coff_incr_data_start) {
      g_coff_incr_data_start = size_or_value;
    }
  }
  g_coff_symbol_slot_capacity = ((file_header.nsymbols >> 1) - 1) + file_header.nsymbols;
  g_coff_symbol_slots = malloc(g_coff_symbol_slot_capacity * 4 + 4);
  if (g_coff_symbol_slots == (c2_coff_slot **)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x12b2);
  }
  order_cursor = g_coff_section_order->head;
  iVar12 = fseek(g_coff_object_file,file_header.symbol_table,0);
  if (iVar12 != 0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x12bb);
  }
  sVar11 = fread(_DstBuf,1,_Count,g_coff_object_file);
  if (sVar11 != _Count) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x12bc);
  }
  size_or_value = 0;
  puVar23 = _DstBuf;
  if (file_header.nsymbols != 0) {
    do {
      slot_cursor = g_coff_symbol_slots;
      if (((*(char *)((int)puVar23 + 3) == '\0' && *(char *)((int)puVar23 + 2) == '\0') &&
          *(char *)((int)puVar23 + 1) == '\0') && (char)*puVar23 == '\0') {
        uStack_34 = puVar23[1];
      }
      else {
        name_buf._0_4_ = *puVar23;
        uStack_34 = 0;
        name_buf._4_4_ = puVar23[1];
      }
      uVar8 = puVar23[4];
      iVar26 = (int)(char)uVar8;
      cVar1 = *(char *)((int)puVar23 + 0x11);
      iVar12 = (int)cVar1;
      uVar4 = puVar23[2];
      sVar20 = (short)puVar23[3];
      sym_type = *(uint16_t *)((int)puVar23 + 0xe);
      bVar6 = (byte)sym_type;
      line_offset = size_or_value;
      switch(iVar26) {
      case 2:
      case 6:
      case 0x65:
      case 0x69:
switchD_10782389_caseD_2:
        slot = (*g_coff_alloc_fn)(0xc);
        slot->kind = 3;
        break;
      case 3:
        if (((bVar6 & 0x30) == 0x20) || (iVar12 == 0)) goto switchD_10782389_caseD_2;
        if (g_coff_incr_section_map[sVar20] == 0) {
          cVar2 = (char)puVar23[8];
          if (((cVar2 == '\x02') || (cVar2 == '\x06')) || (cVar2 == '\a')) {
            line_offset = size_or_value + 1;
            g_coff_symbol_slots[size_or_value] = &g_coff_reserved_slot_record;
            if (0 < iVar12) {
              slot_cursor = slot_cursor + line_offset;
              for (iVar18 = iVar12; iVar18 != 0; iVar18 = iVar18 + -1) {
                *slot_cursor = &g_coff_reserved_slot_record;
                slot_cursor = slot_cursor + 1;
              }
              line_offset = line_offset + iVar12;
            }
          }
          else {
            line_offset = size_or_value + 1;
            g_coff_symbol_slots[size_or_value] = &g_coff_free_slot_record;
            if (0 < iVar12) {
              slot_cursor = slot_cursor + line_offset;
              line_offset = line_offset + iVar12;
              for (iVar18 = iVar12; iVar18 != 0; iVar18 = iVar18 + -1) {
                *slot_cursor = &g_coff_free_slot_record;
                slot_cursor = slot_cursor + 1;
              }
              slot = &g_coff_free_slot_record;
              goto LAB_1078270a;
            }
          }
          slot = &g_coff_free_slot_record;
        }
        else {
          slot = (*g_coff_alloc_fn)(0xc);
          pcVar15 = order_cursor->sec;
          g_coff_symbol_slots[size_or_value] = slot;
          line_offset = size_or_value + 1;
          slot->payload = pcVar15;
          section_desc = pcVar15->desc;
          slot->kind = 2;
          pcVar15->symbol_index = size_or_value;
          if ((section_desc->characteristics & 0x1000) != 0) {
            section_desc->comdat_selection = (uint8_t)puVar23[8];
            sVar20 = *(short *)((int)puVar23 + 0x1e);
            if (sVar20 != 0) {
              section_desc->comdat_assoc = g_coff_incr_section_map[sVar20];
            }
          }
          order_cursor = order_cursor->next;
          iVar18 = iVar12;
          if (0 < iVar12) {
            do {
              slot = (*g_coff_alloc_fn)(0xc);
              g_coff_symbol_slots[line_offset] = slot;
              line_offset = line_offset + 1;
              iVar18 = iVar18 + -1;
              slot->kind = 5;
            } while (iVar18 != 0);
          }
        }
LAB_1078270a:
        if (iVar12 == 0) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1353);
        }
        puVar23 = (uint32_t *)((int)puVar23 + iVar12 * 0x12);
        break;
      default:
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1368);
      case 0xe:
        line_offset = size_or_value + 1;
        slot = &g_coff_free_slot_record;
        g_coff_symbol_slots[size_or_value] = &g_coff_free_slot_record;
        break;
      case 0x67:
        slot = (*g_coff_alloc_fn)(0xc);
        slot->kind = 1;
        file_payload = (*g_coff_alloc_fn)(8);
        slot_cursor = g_coff_symbol_slots;
        slot->payload = file_payload;
        slot_cursor[size_or_value] = slot;
        name_words = (*g_coff_alloc_fn)(iVar12 * 0x12 + 1);
        file_payload->name = (char *)name_words;
        for (iVar18 = iVar12; line_offset = line_offset + 1, iVar18 != 0; iVar18 = iVar18 + -1) {
          *name_words = *(uint32_t *)((int)puVar23 + 0x12);
          name_words[1] = *(uint32_t *)((int)puVar23 + 0x16);
          name_words[2] = *(uint32_t *)((int)puVar23 + 0x1a);
          name_words[3] = *(uint32_t *)((int)puVar23 + 0x1e);
          *(undefined2 *)(name_words + 4) = *(undefined2 *)((int)puVar23 + 0x22);
          slot = (*g_coff_alloc_fn)(0xc);
          g_coff_symbol_slots[line_offset] = slot;
          slot->kind = 5;
          name_words = (uint32_t *)((int)name_words + 0x12);
          puVar23 = (uint32_t *)((int)puVar23 + 0x12);
        }
        *(undefined1 *)name_words = 0;
      }
      size_or_value = line_offset;
      if (slot->kind == 3) {
        pcVar14 = (*g_coff_alloc_fn)(0x12);
        *(uint32_t *)(pcVar14 + 8) = uVar4;
        pcVar14[0x10] = (char)uVar8;
        if (sVar20 != 0) {
          if (g_coff_incr_section_map[sVar20] != 0) {
            sVar20 = -2 - g_coff_incr_section_map[sVar20];
          }
          *(short *)(pcVar14 + 0xc) = sVar20;
        }
        *(uint16_t *)(pcVar14 + 0xe) = sym_type;
        pcVar14[0x11] = cVar1;
        if (uStack_34 == 0) {
          strncpy(pcVar14,name_buf,8);
        }
        else {
          pcVar14[0] = '\0';
          pcVar14[1] = '\0';
          pcVar14[2] = '\0';
          pcVar14[3] = '\0';
          *(uint32_t *)(pcVar14 + 4) = uStack_34;
        }
        slot_cursor = g_coff_symbol_slots;
        slot->payload = pcVar14;
        slot_cursor[line_offset] = slot;
        size_or_value = line_offset + 1;
        if ((iVar26 != 0x65) && ((-1 < *(short *)(pcVar14 + 0xc) || ((bVar6 & 0x30) == 0x20)))) {
          prevobj_read_dword();
          local_54 = prevobj_read_dword();
          slot->key = local_54;
          if ((iVar26 == 0x69) &&
             (iVar26 = coff_symbol_is_not_dllimport_var(local_54), slot_cursor = g_coff_symbol_slots
             , iVar26 != 0)) {
            size_or_value = line_offset + 2;
            g_coff_symbol_slots[line_offset] = &g_coff_free_slot_record;
            slot_cursor[line_offset + 1] = &g_coff_free_slot_record;
            puVar23 = (uint32_t *)((int)puVar23 + 0x12);
            goto LAB_1078253a;
          }
          coff_hash64_insert(local_54,line_offset);
        }
        if (iVar12 == 0) {
          if (((bVar6 & 0x30) == 0x20) && (*(short *)(pcVar14 + 0xc) < -2)) {
            coff_note_inline_debug_function(local_54);
          }
        }
        else {
          slot = (*g_coff_alloc_fn)(0xc);
          g_coff_symbol_slots[size_or_value] = slot;
          slot->kind = 4;
          size_or_value = line_offset + 2;
          name_words = (*g_coff_alloc_fn)(0x12);
          slot->payload = name_words;
          *name_words = *(uint32_t *)((int)puVar23 + 0x12);
          name_words[1] = *(uint32_t *)((int)puVar23 + 0x16);
          name_words[2] = *(uint32_t *)((int)puVar23 + 0x1a);
          name_words[3] = *(uint32_t *)((int)puVar23 + 0x1e);
          *(undefined2 *)(name_words + 4) = *(undefined2 *)((int)puVar23 + 0x22);
          puVar23 = (uint32_t *)((int)puVar23 + 0x12);
        }
      }
LAB_1078253a:
      puVar23 = (uint32_t *)((int)puVar23 + 0x12);
    } while (size_or_value < file_header.nsymbols);
  }
  g_coff_symbol_slot_count = file_header.nsymbols;
  g_coff_symbol_append_index = file_header.nsymbols;
  free(_DstBuf);
  prevobj_read_dword();
  prevobj_read_dword();
  sVar11 = fread(&file_header,1,4,g_coff_object_file);
  if (sVar11 != 4) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x13fb);
  }
  sVar11 = CONCAT22(file_header.nsections,file_header.machine) - 4;
  _DstBuf_00 = malloc(sVar11);
  if (_DstBuf_00 == (void *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1401);
  }
  sVar19 = fread(_DstBuf_00,1,sVar11,g_coff_object_file);
  if (sVar19 != sVar11) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1403);
  }
  desc = coff_list_next(g_coff_sections);
  while (slot_cursor = g_coff_symbol_slots, size_or_value = g_coff_symbol_slot_count,
        desc != (c2_coff_section *)0x0) {
    if ((desc->flags & 0x20) != 0) {
      desc->name = desc->name + (int)_DstBuf_00 + -4;
      desc->flags = desc->flags & 0xffdf;
    }
    desc = coff_list_next(g_coff_sections);
  }
  for (; size_or_value != 0; size_or_value = size_or_value - 1) {
    if (((*slot_cursor)->kind == 3) && (piVar5 = (*slot_cursor)->payload, *piVar5 == 0)) {
      piVar5[1] = (int)_DstBuf_00 + piVar5[1] + -4;
    }
    slot_cursor = slot_cursor + 1;
  }
  iVar12 = fseek(g_coff_object_file,0,0);
  if (iVar12 != 0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1433);
  }
  iVar12 = _chsize(g_coff_object_file->_file,g_coff_data_end);
  if (iVar12 != 0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1434);
  }
  return 1;
}

