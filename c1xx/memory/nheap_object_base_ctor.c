void __thiscall nheap_object_base_ctor(c1xx_pch_stream_reader *obj,int kind,c1xx_pch_image *image)

{
  obj->header_offset = 0;
  obj->state = 0;
  obj->kind = kind;
  obj->owner = image;
  obj->vtbl = (c1xx_pch_stream_reader_vtbl *)&PTR__purecall_104c4d78;
  return;
}

