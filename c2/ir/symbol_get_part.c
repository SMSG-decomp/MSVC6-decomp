c2_symbol * __fastcall symbol_get_part(c2_symbol *sym,uint16_t type,uint32_t size,int32_t offset)

{
  uint8_t kind;
  byte bVar1;
  c2_tuple *pcVar2;
  c2_fe_symbol *pcVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  c2_symbol *pcVar7;
  c2_symbol *pcVar8;
  int iVar9;
  c2_symbol *pcVar10;
  c2_symbol *pcVar11;
  uint32_t size_00;
  uint16_t type_00;
  uint uVar12;
  ushort local_4;
  
  if ((type & 0xfff) != 0) {
    size = type & 0xfff;
  }
  pcVar11 = sym->storage;
  pcVar2 = sym->def;
  iVar5 = sym->offset + offset;
  if (pcVar11->cls == '\x01') {
    pcVar11 = reg_find_subreg(pcVar11,size * 8,iVar5 * 8);
    return pcVar11;
  }
  pcVar7 = pcVar11;
  if (size == 0) {
    uVar12 = 0;
    pcVar8 = (c2_symbol *)0x0;
    pcVar10 = pcVar11;
    iVar6 = iVar5;
    if (pcVar11 != (c2_symbol *)0x0) {
      do {
        if (((pcVar7->offset == iVar5) && (uVar12 <= (uint)pcVar7->size)) &&
           ((pcVar7->type & 0xf000) == 0x5000)) {
          pcVar8 = pcVar7;
          uVar12 = pcVar7->size;
        }
        pcVar7 = pcVar7->part_next;
      } while (pcVar7 != (c2_symbol *)0x0);
      if (pcVar8 != (c2_symbol *)0x0) {
        return pcVar8;
      }
    }
    for (; pcVar10 != (c2_symbol *)0x0; pcVar10 = pcVar10->part_next) {
      iVar9 = pcVar10->offset + pcVar10->size;
      if (iVar6 < iVar9) {
        iVar6 = iVar9;
      }
    }
    size = iVar6 - iVar5;
    if (size < 0x1000) {
      local_4 = (ushort)size | 0x5000;
    }
    else {
      local_4 = 0x5000;
    }
  }
  else {
    for (; pcVar7 != (c2_symbol *)0x0; pcVar7 = pcVar7->part_next) {
      iVar6 = types_compatible(pcVar7->type,type);
      if (((iVar6 != 0) && (pcVar7->offset == iVar5)) && (pcVar7->size == size)) {
        return pcVar7;
      }
    }
    pcVar3 = pcVar11->storage->fe;
    local_4 = type;
    if (((pcVar3 != (c2_fe_symbol *)0x0) && (pcVar3->cls == '\x01')) &&
       (((((byte)pcVar3->storage & 0x70) == 0x10 &&
         (((pcVar3->name == (char *)0x0 && ((pcVar3->storage & 0x80000) != 0)) &&
          (pcVar11->offset == iVar5)))) && ((type & 0xf000) == 0x3000)))) {
      return pcVar11;
    }
  }
  kind = pcVar11->cls;
  pcVar7 = symbol_alloc(kind);
  bVar1 = pcVar11->flags5;
  pcVar7->type = local_4;
  pcVar7->offset = iVar5;
  pcVar7->size = size;
  bVar4 = (bVar1 ^ pcVar7->flags5) & 1 ^ pcVar7->flags5;
  pcVar7->cls = kind;
  pcVar7->flags5 = bVar4;
  bVar1 = pcVar11->flags5;
  pcVar7->storage = pcVar11;
  bVar4 = (bVar1 ^ bVar4) & 2 ^ bVar4;
  pcVar7->flags5 = bVar4;
  pcVar7->flags5 = (bVar4 ^ pcVar11->flags5) & 4 ^ bVar4;
  iVar6 = pcVar11->offset;
  pcVar7->def = pcVar2;
  if (((iVar5 < iVar6) || (pcVar11->size + iVar6 < (int)(iVar5 + size))) &&
     ((pcVar11->storage->fe != (c2_fe_symbol *)0x0 &&
      ((((size_00 = (iVar5 - iVar6) + size, kind != '\x03' && (kind != '\x04')) &&
        ((kind != '\x05' && (kind != '\x06')))) || ((int)(size_00 - pcVar11->fe->size) < 5)))))) {
    if ((pcVar11->type & 0xfff) != 0) {
      if (iVar5 != 0) {
        if ((int)size_00 < 0x1000) {
          type_00 = (ushort)size_00 | 0x5000;
        }
        else {
          type_00 = 0x5000;
        }
        pcVar10 = symbol_get_part(pcVar11,type_00,size_00,0);
        pcVar11 = pcVar10->part_next;
        pcVar7->storage = pcVar10;
        pcVar10->part_next = pcVar7;
        pcVar7->part_next = pcVar11;
        return pcVar7;
      }
      alias_replace_symbol(pcVar11,pcVar7);
      pcVar3 = pcVar11->fe;
      pcVar7->storage = pcVar7;
      pcVar7->fe = pcVar3;
      pcVar11->fe = (c2_fe_symbol *)0x0;
      pcVar3->storage_sym = pcVar7;
      pcVar7->part_next = (c2_symbol *)0x0;
      if (pcVar11 == (c2_symbol *)0x0) {
        return pcVar7;
      }
      do {
        pcVar10 = pcVar11->part_next;
        pcVar11->part_next = pcVar7->part_next;
        pcVar11->storage = pcVar7;
        pcVar7->part_next = pcVar11;
        pcVar11 = pcVar10;
      } while (pcVar10 != (c2_symbol *)0x0);
      return pcVar7;
    }
    pcVar11->size = size_00;
  }
  if (((kind == '\x03') && (pcVar11->size < pcVar7->size)) && (iVar5 == 0)) {
    pcVar7->storage = pcVar7;
    pcVar7->part_next = (c2_symbol *)0x0;
    if (pcVar11 != (c2_symbol *)0x0) {
      do {
        pcVar10 = pcVar11->part_next;
        pcVar11->part_next = pcVar7->part_next;
        pcVar11->storage = pcVar7;
        pcVar7->part_next = pcVar11;
        pcVar11 = pcVar10;
      } while (pcVar10 != (c2_symbol *)0x0);
      return pcVar7;
    }
  }
  else {
    pcVar10 = pcVar11->part_next;
    pcVar7->storage = pcVar11;
    pcVar7->part_next = pcVar10;
    pcVar11->part_next = pcVar7;
  }
  return pcVar7;
}

