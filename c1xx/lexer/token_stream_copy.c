void * __thiscall token_stream_copy(c1xx_token_stream *this,c1xx_token_stream *src)

{
  byte bVar1;
  byte bVar2;
  
  this->start_position = src->start_position;
  this->position = src->position;
  (this->first).chunk = (src->first).chunk;
  (this->first).index = (src->first).index;
  (this->first).arena = (src->first).arena;
  (this->read).chunk = (src->read).chunk;
  (this->read).index = (src->read).index;
  (this->read).arena = (src->read).arena;
  (this->write).chunk = (src->write).chunk;
  (this->write).index = (src->write).index;
  (this->write).arena = (src->write).arena;
  this->arena = src->arena;
  bVar2 = (src->flags ^ this->flags) & 1 ^ this->flags;
  this->flags = bVar2;
  bVar1 = src->flags;
  this->vtbl = (c1xx_token_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
  this->flags = (bVar1 ^ bVar2) & 2 ^ bVar2;
  return this;
}

