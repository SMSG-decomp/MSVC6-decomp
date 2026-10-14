void * __thiscall token_stream_init(c1xx_token_stream *this,int arena,byte from_source)

{
  int iVar1;
  int iVar2;
  uint *buffer;
  
  iVar1 = g_token_position;
  buffer = (uint *)&this->first;
  this->start_position = g_token_position;
  this->position = iVar1;
  token_buffer_init((c1xx_token_cursor *)buffer,arena);
  this->arena = arena;
  this->vtbl = (c1xx_token_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
  (this->read).chunk = (c1_token_chunk *)*buffer;
  (this->read).index = (this->first).index;
  (this->read).arena = (this->first).arena;
  iVar1 = (this->first).index;
  (this->write).chunk = (c1_token_chunk *)*buffer;
  iVar2 = (this->first).arena;
  (this->write).index = iVar1;
  (this->write).arena = iVar2;
  this->flags = (this->flags ^ from_source) & 1 ^ this->flags;
  return this;
}

