void __fastcall coff_write_fill(uint8_t value,uint32_t count)

{
  c2_coff_chunk *new_chunk;
  size_t sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint32_t uVar5;
  uint8_t *dst;
  c2_coff_data *data;
  c2_coff_chunk *old_chunk;
  
  data = g_coff_current_section_data;
  if (g_coff_current_section_data->count_only != 1) {
    if (g_coff_current_section_data->buffered != 0) {
      if (500 - g_coff_current_section_data->fill < count) {
        do {
          uVar4 = 500 - data->fill;
          count = count - uVar4;
          dst = data->cur->data + data->fill;
          for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(uint *)dst = CONCAT22(CONCAT11(value,value),CONCAT11(value,value));
            dst = dst + 4;
          }
          for (uVar2 = uVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *dst = value;
            dst = dst + 1;
          }
          uVar5 = uVar4 + data->fill;
          data->fill = uVar5;
          if (uVar5 != 500) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xdbe);
          }
          new_chunk = coff_alloc_chunk();
          old_chunk = data->cur;
          data->cur = new_chunk;
          data->fill = 0;
          new_chunk->next = old_chunk->next;
          old_chunk->next = new_chunk;
          data->full = data->full + 500;
        } while (500 < count);
      }
      dst = data->cur->data + data->fill;
      for (uVar2 = count >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(uint *)dst = CONCAT22(CONCAT11(value,value),CONCAT11(value,value));
        dst = dst + 4;
      }
      for (uVar2 = count & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *dst = value;
        dst = dst + 1;
      }
      data->fill = data->fill + count;
      data->writes = data->writes + 1;
      return;
    }
    dst = g_coff_fill_buffer;
    for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(uint *)dst = CONCAT22(CONCAT11(value,value),CONCAT11(value,value));
      dst = dst + 4;
    }
    for (; count < 0x51; count = count - 0x50) {
      sVar1 = fwrite(g_coff_fill_buffer,0x50,1,g_coff_object_file);
      if (sVar1 != 1) {
        (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xdae);
      }
      data->fill = data->fill + 0x50;
    }
    if (count == 0) goto LAB_1074fef0;
    sVar1 = fwrite(g_coff_fill_buffer,count,1,g_coff_object_file);
    if (sVar1 != 1) {
      (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xdb3);
    }
  }
  data->fill = data->fill + count;
LAB_1074fef0:
  data->writes = data->writes + 1;
  return;
}

