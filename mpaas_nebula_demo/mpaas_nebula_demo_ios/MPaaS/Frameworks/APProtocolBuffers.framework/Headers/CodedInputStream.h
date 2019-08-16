// Protocol Buffers for Objective C
//
// Copyright 2010 Booyah Inc.
// Copyright 2008 Cyrus Najmabadi
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

@class PBExtensionRegistry;
@class PBUnknownFieldSetBuilder;
@protocol PBMessageBuilder;
@class APPBGeneratedMessage;

/**
 * Reads and decodes protocol message fields.
 *
 * This class contains two kinds of methods:  methods that read specific
 * protocol message constructs and field types (e.g. {@link #readTag()} and
 * {@link #readInt32()}) and methods that read low-level values (e.g.
 * {@link #readRawVarint32()} and {@link #readRawBytes}).  If you are reading
 * encoded protocol messages, you should use the former methods, but if you are
 * reading some other format of your own design, use the latter.
 *
 * @author Cyrus Najmabadi
 */
@interface PBCodedInputStream : NSObject {
@private
  NSMutableData* buffer;
  SInt32 bufferSize;
  SInt32 bufferSizeAfterLimit;
  SInt32 bufferPos;
  NSInputStream* input;
  SInt32 lastTag;

  /**
   * The total number of bytes read before the current buffer.  The total
   * bytes read up to the current position can be computed as
   * {@code totalBytesRetired + bufferPos}.
   */
  SInt32 totalBytesRetired;

  /** The absolute position of the end of the current message. */
  SInt32 currentLimit;

  /** See setRecursionLimit() */
  SInt32 recursionDepth;
  SInt32 recursionLimit;

  /** See setSizeLimit() */
  SInt32 sizeLimit;
}
//用data初始化stream
+ (PBCodedInputStream*) streamWithData:(NSData*) data;
//用NSInputStream初始化stream
+ (PBCodedInputStream*) streamWithInputStream:(NSInputStream*) input;

/**
 * Attempt to read a field tag, returning zero if we have reached EOF.
 * Protocol message parsers use this to read tags, since a protocol message
 * may legally end wherever a tag occurs, and zero is not a valid tag number.
 */
- (SInt32) readTag;
//bf
- (BOOL) refillBuffer:(BOOL) mustSucceed;
//读取Float64类型
- (Float64) readDouble;
//读取Float32类型
- (Float32) readFloat;
//读取UInt64类型
- (SInt64) readUInt64;
//读取UInt32类型
- (SInt32) readUInt32;
//读取Int64类型
- (SInt64) readInt64;
//读取SInt32类型
- (SInt32) readInt32;
//读取SInt64类型
- (SInt64) readFixed64;
//读取SInt32类型
- (SInt32) readFixed32;
//读取SInt32类型
- (SInt32) readEnum;
//读取SInt32类型
- (SInt32) readSFixed32;
//读取SInt64类型
- (SInt64) readSFixed64;
//读取SInt32类型
- (SInt32) readSInt32;
//读取SInt64类型
- (SInt64) readSInt64;

/**
 * Read one byte from the input.
 *
 * @throws InvalidProtocolBuffer The end of the stream or the current
 *                                        limit was reached.
 */
- (int8_t) readRawByte;

/**
 * Read a raw Varint from the stream.  If larger than 32 bits, discard the
 * upper bits.
 */
- (SInt32) readRawVarint32;
//读取Varint64
- (SInt64) readRawVarint64;
//读取LittleEndian32
- (SInt32) readRawLittleEndian32;
//读取LittleEndian64
- (SInt64) readRawLittleEndian64;

/**
 * Read a fixed size of bytes from the input.
 *
 * @throws InvalidProtocolBuffer The end of the stream or the current
 *                                        limit was reached.
 */
- (NSData*) readRawData:(SInt32) size;

/**
 * Reads and discards a single field, given its tag value.
 *
 * @return {@code false} if the tag is an endgroup tag, in which case
 *         nothing is skipped.  Otherwise, returns {@code true}.
 */
- (BOOL) skipField:(SInt32) tag;


/**
 * Reads and discards {@code size} bytes.
 *
 * @throws InvalidProtocolBuffer The end of the stream or the current
 *                                        limit was reached.
 */
- (void) skipRawData:(SInt32) size;

/**
 * Reads and discards an entire message.  This will read either until EOF
 * or until an endgroup tag, whichever comes first.
 */
- (void) skipMessage;

//是否结束
- (BOOL) isAtEnd;
//push限制
- (SInt32) pushLimit:(SInt32) byteLimit;
//recompute限制
- (void) recomputeBufferSizeAfterLimit;
//pop限制
- (void) popLimit:(SInt32) oldLimit;
//bytesUntilLimit
- (SInt32) bytesUntilLimit;


/** Read an embedded message field value from the stream. */
- (void) readMessage:(id<PBMessageBuilder>) builder extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
/** Read an embedded message field value from the stream. */
- (void) readAPMessage:(APPBGeneratedMessage*) message extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

//读取BOOL
- (BOOL) readBool;
//读取string
- (NSString*) readString;
//读取data
- (NSData*) readData;

//- (void) readGroup:(SInt32) fieldNumber builder:(id<PBMessageBuilder>) builder extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

/**
 * Reads a {@code group} field value from the stream and merges it into the
 * given {@link UnknownFieldSet}.
 */
- (void) readUnknownGroup:(SInt32) fieldNumber builder:(PBUnknownFieldSetBuilder*) builder;

/**
 * Verifies that the last call to readTag() returned the given tag value.
 * This is used to verify that a nested group ended with the correct
 * end tag.
 *
 * @throws InvalidProtocolBuffer {@code value} does not match the
 *                                        last tag.
 */
- (void) checkLastTagWas:(SInt32) value;

@end
