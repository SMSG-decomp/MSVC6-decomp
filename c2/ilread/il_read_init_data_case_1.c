void il_read_init_data_case_1
               (c2_init *item,c2_init *group,int raw_bytes_kind,c2_init *group_home,c2_init *tail,
               int in_repeat)

{
  c2_init *pcVar1;
  c2_init *pcVar2;
  char cVar3;
  int16_t iVar4;
  ushort uVar5;
  int iVar6;
  int32_t iVar7;
  char *out;
  uint8_t *counted_bytes;
  c2_init_bit_pair *pair;
  uint32_t uVar8;
  uint32_t *cursor;
  uint32_t *merged;
  uint uVar9;
  c2_init_bit_pair **pair_link;
  uint16_t uVar10;
  uint uVar11;
  uint32_t *dst;
  ulonglong uVar12;
  uint32_t *item_bytes;
  
code_r0x1075753e:
  (item->u18).repeat = 1;
LAB_10757545:
  iVar6 = il_read_byte();
  uVar10 = (uint16_t)(char)iVar6;
  (item->u08).data.value_kind = uVar10;
  iVar6 = il_read_byte();
  (item->u08).data.size = (short)(char)iVar6;
  switch((short)(char)iVar6) {
  case 1:
    iVar6 = il_read_byte();
    *(char *)((int)&item->u08 + 4) = (char)iVar6;
    break;
  case 2:
    iVar4 = il_read_short();
    *(int16_t *)((int)&item->u08 + 4) = iVar4;
    break;
  case 4:
    if (uVar10 == 5) {
      uVar8 = il_read_4_bytes();
      (item->u08).header.offset = uVar8;
    }
    else {
      iVar7 = il_read_long();
      (item->u08).header.offset = iVar7;
    }
    break;
  case 8:
    if (uVar10 == 5) {
      uVar12 = il_read_8_bytes();
      *(ulonglong *)((int)&item->u08 + 4) = uVar12;
    }
    else {
      il_read_compact_qword_file(&(item->u08).header.offset,(int32_t *)&(item->u08).header.sym_id);
    }
    break;
  case 10:
    cursor = il_read_12_bytes((uint32_t *)&stack0x00000020);
    (item->u08).header.offset = *cursor;
    (item->u08).header.sym_id = cursor[1];
    (item->u08).header.placed = cursor[2];
  }
LAB_107575ad:
  if (in_repeat == 0) {
    tail->next = item;
    pcVar1 = group;
    pcVar2 = group_home;
    tail = item;
    if (group != (c2_init *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0xa26);
    }
  }
  else {
    pcVar1 = item;
    pcVar2 = item;
    if (group != (c2_init *)0x0) {
      if (group->kind != 1) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0xa2e);
      }
      if ((group->u08).data.value_kind == (uint16_t)raw_bytes_kind) {
        cursor = *(uint32_t **)((int)&group->u08 + 4);
      }
      else {
        cursor = (uint32_t *)&(group->u08).header.offset;
      }
      if ((item->u08).data.value_kind == (uint16_t)raw_bytes_kind) {
        item_bytes = (uint32_t *)(item->u08).header.offset;
      }
      else {
        item_bytes = (uint32_t *)&(item->u08).header.offset;
      }
      uVar5 = (item->u08).data.size;
      uVar11 = (uint)(short)(group->u08).data.size;
      merged = arena_alloc(0,uVar11 + uVar5);
      dst = merged;
      for (uVar9 = uVar11 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *dst = *cursor;
        cursor = cursor + 1;
        dst = dst + 1;
      }
      uVar10 = (group_home->u08).data.size;
      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(char *)dst = (char)*cursor;
        cursor = (uint32_t *)((int)cursor + 1);
        dst = (uint32_t *)((int)dst + 1);
      }
      cursor = (uint32_t *)((int)(short)uVar10 + (int)merged);
      for (uVar9 = (uint)(uVar5 >> 2); uVar9 != 0; uVar9 = uVar9 - 1) {
        *cursor = *item_bytes;
        item_bytes = item_bytes + 1;
        cursor = cursor + 1;
      }
      for (uVar9 = uVar5 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(char *)cursor = (char)*item_bytes;
        item_bytes = (uint32_t *)((int)item_bytes + 1);
        cursor = (uint32_t *)((int)cursor + 1);
      }
      (group_home->u08).data.size = (group_home->u08).data.size + (item->u08).data.size;
      (group_home->u08).data.value_kind = 6;
      *(uint32_t **)((int)&group_home->u08 + 4) = merged;
      init_records_free(item);
      pcVar1 = group_home;
      pcVar2 = group_home;
    }
  }
  while( true ) {
    group_home = pcVar2;
    group = pcVar1;
    iVar6 = il_read_byte();
    iVar6 = (int)(char)iVar6;
    if (iVar6 == 7) {
      return;
    }
    raw_bytes_kind = 6;
    if (iVar6 != 6) break;
    in_repeat = 0;
    group_home = (c2_init *)0x0;
    tail->next = group;
    pcVar1 = group_home;
    pcVar2 = group_home;
    tail = group;
  }
  item = alloc_init_record(iVar6);
  switch(iVar6) {
  case 1:
    goto code_r0x1075753e;
  case 2:
    uVar9 = il_read_id();
    (item->u08).address.target_id = uVar9;
    iVar7 = il_read_long();
    (item->u08).header.offset = iVar7;
    iVar6 = il_read_byte();
    (item->u08).address.size = (uint8_t)iVar6;
    goto LAB_107575ad;
  case 3:
    (item->u18).repeat = 1;
    break;
  case 4:
    iVar6 = il_read_byte();
    (item->u08).align = (uint8_t)iVar6;
    goto LAB_107575ad;
  case 5:
    iVar7 = il_read_long();
    (item->u18).repeat = iVar7;
    in_repeat = 1;
    iVar6 = il_read_byte();
    cVar3 = (char)iVar6;
    if ((cVar3 != '\x01') && (cVar3 != '\x03')) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x988);
    }
    item->kind = 1;
    if (cVar3 == '\x01') goto LAB_10757545;
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0xa21);
  case 8:
    uVar8 = il_read_long();
    (item->u08).address.target_id = uVar8;
    goto LAB_107575ad;
  case 0xb:
    goto switchD_10757609_caseD_b;
  case 0x10:
    goto switchD_10757609_caseD_10;
  }
  item->kind = 1;
  uVar5 = il_read_short();
  (item->u08).data.size = uVar5;
  out = arena_alloc(0,(uint)uVar5);
  *(char **)((int)&item->u08 + 4) = out;
  il_read_bytes((uint)uVar5,out);
  (item->u08).data.value_kind = 6;
  goto LAB_107575ad;
switchD_10757609_caseD_10:
  pair_link = (c2_init_bit_pair **)&item->u18;
  if (iVar6 != 0x11) {
    do {
      pair = arena_alloc(0,6);
      *pair_link = pair;
      iVar6 = il_read_byte();
      pair->first = (uint8_t)iVar6;
      iVar6 = il_read_byte();
      pair->second = (uint8_t)iVar6;
      iVar6 = il_read_byte();
      pair_link = &pair->next;
    } while ((char)iVar6 != '\x11');
  }
  raw_bytes_kind = 6;
  goto LAB_10757545;
switchD_10757609_caseD_b:
  item->kind = 1;
  (item->u18).repeat = 1;
  (item->u08).data.value_kind = 6;
  uVar5 = il_read_short();
  uVar9 = uVar5 + 2;
  (item->u08).data.size = (uint16_t)uVar9;
  counted_bytes = arena_alloc(4,uVar9 & 0xffff);
  *counted_bytes = (uint8_t)uVar5;
  (item->u08).header.offset = (int32_t)counted_bytes;
  counted_bytes[1] = (uint8_t)(uVar5 >> 8);
  il_read_bytes((uint)uVar5,(char *)(counted_bytes + 2));
  raw_bytes_kind = 6;
  goto LAB_107575ad;
}

