void __fastcall il_read_init_data(c2_init *rec)

{
  uint16_t uVar1;
  c2_init *pcVar2;
  char cVar3;
  int16_t iVar4;
  ushort uVar5;
  int iVar6;
  c2_init *item;
  char *out;
  uint32_t uVar7;
  uint8_t *counted_bytes;
  int32_t iVar8;
  c2_init_bit_pair *pair;
  uint32_t *merged;
  uint uVar9;
  c2_init_bit_pair **pair_link;
  uint32_t *cursor;
  c2_init *pcVar10;
  uint uVar11;
  uint32_t *dst;
  c2_init *group_home;
  c2_init *tail;
  uint32_t *item_bytes;
  c2_init *group;
  bool in_repeat;
  
  group_home = (c2_init *)0x0;
  in_repeat = false;
  iVar6 = il_read_byte();
  cVar3 = (char)iVar6;
  group = (c2_init *)0x0;
  tail = rec;
  pcVar2 = group_home;
  do {
    iVar6 = (int)cVar3;
    if (iVar6 == 7) {
      return;
    }
    if (iVar6 == 6) {
      in_repeat = false;
      group_home = (c2_init *)0x0;
      tail->next = group;
      pcVar10 = group_home;
      tail = group;
      goto il_read_init_data_part;
    }
    item = alloc_init_record(iVar6);
    switch(iVar6) {
    case 1:
      (item->u18).repeat = 1;
      goto LAB_10757545;
    case 2:
      uVar9 = il_read_id();
      (item->u08).address.target_id = uVar9;
      iVar8 = il_read_long();
      (item->u08).header.offset = iVar8;
      iVar6 = il_read_byte();
      (item->u08).address.size = (uint8_t)iVar6;
      break;
    case 3:
      (item->u18).repeat = 1;
LAB_10757617:
      item->kind = 1;
      uVar5 = il_read_short();
      (item->u08).data.size = uVar5;
      out = arena_alloc(0,(uint)uVar5);
      *(char **)((int)&item->u08 + 4) = out;
      il_read_bytes((uint)uVar5,out);
      (item->u08).data.value_kind = 6;
      break;
    case 4:
      iVar6 = il_read_byte();
      (item->u08).align = (uint8_t)iVar6;
      break;
    case 5:
      iVar8 = il_read_long();
      (item->u18).repeat = iVar8;
      in_repeat = true;
      iVar6 = il_read_byte();
      cVar3 = (char)iVar6;
      if ((cVar3 != '\x01') && (cVar3 != '\x03')) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x988);
      }
      item->kind = 1;
      if (cVar3 != '\x01') goto LAB_10757617;
      goto LAB_10757545;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0xa21);
    case 8:
      uVar7 = il_read_long();
      (item->u08).address.target_id = uVar7;
      break;
    case 0xb:
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
      break;
    case 0x10:
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
LAB_10757545:
      iVar6 = il_read_byte();
      *(short *)&item->u08 = (short)(char)iVar6;
      iVar6 = il_read_byte();
      *(short *)((int)&item->u08 + 2) = (short)(char)iVar6;
      switch((char)iVar6) {
      case '\0':
        halt_baddata();
      case '\x01':
        iVar6 = il_read_byte();
        *(char *)((int)&item->u08 + 4) = (char)iVar6;
        break;
      case '\x02':
        iVar4 = il_read_short();
        *(int16_t *)((int)&item->u08 + 4) = iVar4;
      }
    }
    if (in_repeat) {
      pcVar10 = item;
      group_home = item;
      if (group != (c2_init *)0x0) {
        if (group->kind != 1) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0xa2e);
        }
        if ((group->u08).data.value_kind == 6) {
          cursor = *(uint32_t **)((int)&group->u08 + 4);
        }
        else {
          cursor = (uint32_t *)&(group->u08).header.offset;
        }
        if ((item->u08).data.value_kind == 6) {
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
        uVar1 = (pcVar2->u08).data.size;
        for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *(char *)dst = (char)*cursor;
          cursor = (uint32_t *)((int)cursor + 1);
          dst = (uint32_t *)((int)dst + 1);
        }
        cursor = (uint32_t *)((int)(short)uVar1 + (int)merged);
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
        (pcVar2->u08).data.size = (pcVar2->u08).data.size + (item->u08).data.size;
        (pcVar2->u08).data.value_kind = 6;
        *(uint32_t **)((int)&pcVar2->u08 + 4) = merged;
        init_records_free(item);
        pcVar10 = pcVar2;
        group_home = pcVar2;
      }
    }
    else {
      tail->next = item;
      pcVar10 = group;
      group_home = pcVar2;
      tail = item;
      if (group != (c2_init *)0x0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0xa26);
      }
    }
il_read_init_data_part:
    iVar6 = il_read_byte();
    cVar3 = (char)iVar6;
    group = pcVar10;
    pcVar2 = group_home;
  } while( true );
}

