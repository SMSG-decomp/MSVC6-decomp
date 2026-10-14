c1xx_pch_stream_reader * __thiscall
nheap_record_init_4c(c1xx_pch_stream_reader *obj,c1xx_pch_stream_reader *from,c1xx_pch_image *image)

{
  nheap_object_base_ctor(obj,from->kind,image);
  obj->file_offset = 0;
  obj->base = from->base;
  obj->size = from->size;
  obj->desc_word = from->desc_word;
  obj->vtbl = (c1xx_pch_stream_reader_vtbl *)&PTR_pch_segment_map_view_104c4d3c;
  obj->state = 1;
  return obj;
}

